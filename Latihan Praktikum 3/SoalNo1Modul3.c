#include <stdio.h>

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int N;

    printf("N: ");
    scanf("%d", &N);
    
    printf("%d\n", faktorial(N));
    
    return 0;
}