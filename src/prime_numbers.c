#include<stdio.h>

void print_prime(int n);
void factorize(int n);

int main()
{
    int n;

    printf("Put the value of n: ");
    scanf("%d", &n);

    factorize(n);
    print_prime(n);

    return 0;
}

void print_prime(int n)
{
    int prime;

    if(n<=2) {
        printf("There's no Prime numbers");
        return;
    }

    printf("Prime numbers are ");
    printf("2");
    
    for(int i=3; i<n; i++) {
        prime = 1;
        for(int j=2; j<i; j++) {
            if(i%j == 0) {
                prime = 0;
                break;
            }
        }

        if(prime==1) {
            printf(", %d", i);
        }
    }
    printf("\n");
}
void factorize(int n)
{
    int i = 2, first_time = 1;
    printf("Prime factors are ");

    while(n!=1) {
        if(n%i==0) {
            n /= i;
            if(first_time) first_time = 0;
            else printf(", ");
            printf("%d", i);
        } else {
            i++;
        }
    }
    printf("\n");
}