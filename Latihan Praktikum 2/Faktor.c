#include <stdio.h>


int main() {
    int n;
    int factor;

    factor= 2 ;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer greater than 0.\n");
        }
    do
    {
        while (n % factor == 0)
        {
            printf("%d ", factor);
            n = n / factor ;
        }
        if (n > 1)
        {
            factor = factor + 1;
        }

    } while (factor < n );

    if (n>1)
    {
        printf("%d",n);

    }

    return 0;
}