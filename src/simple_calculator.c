#include<stdio.h>

int calculate(int num1, int num2, char operator);

int main()
{

    int num1, num2, num3, mode, temp, int_temp, result;
    char operator1, operator2, char_temp;

    printf("Enter the calculator mode (1:Normal, 2:Extended): ");
    scanf("%d", &mode);

    if(mode==1) {
        printf("Put two integers: ");
        scanf("%d, %d", &num1, &num2);
        printf("Put the operator: ");
        scanf(" %c", &operator1);  // add space before format-string to ignore new-line character

        result = calculate(num1, num2, operator1);

    } else if(mode==2) {
        printf("Put three integers: ");
        scanf("%d, %d, %d", &num1, &num2, &num3);
        printf("Put two operators: ");
        scanf(" %c, %c", &operator1, &operator2);  // add space before format-string to ignore new-line character

        if((operator1 == '+' || operator1 == '-') && (operator2 == '*' || operator2 == '/' || operator2 == '%')) {
            int_temp = num1;
            num1 = num2;
            num2 = num3;
            num3 = int_temp;
            char_temp = operator1;
            operator1 = operator2;
            operator2 = char_temp;
        }

        temp = calculate(num1, num2, operator1);
        result = calculate(temp, num3, operator2);

    }

    printf("The result is %d", result);

    return 0;
}

int calculate(int num1, int num2, char operator)
{
    int result = 0;

    if(operator == '+') {
            result = num1 + num2;
        } else if(operator == '-') {
            result = num1 - num2;
        } else if(operator == '*') {
            result = num1 * num2;
        } else if(operator == '/') {
            if(num2==0) {
                printf("ERROR : Division by Zero");
                return -1;
            } else {
                result = num1 / num2;  // int/int results quotient
            }
        } else if(operator == '%') {
            if(num2==0) {
                printf("ERROR : Division by Zero");
                return -1;
            } else {
                result = num1 % num2;
            }
        }

        return result;
}