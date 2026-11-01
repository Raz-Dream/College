#include <stdio.h>
#include <math.h>

int polaBilangan(int n) {

    if (n == 1) {
        return 1;
    }

    else {

        return polaBilangan(n - 1) + (int)pow(n, 2);
    }
}

int main() {
    int N;
    
    printf("N: ");
    scanf("%d", &N);
    
    printf("%d", polaBilangan(N));
    
    return 0;
}