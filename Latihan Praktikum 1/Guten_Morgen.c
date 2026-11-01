#include <stdio.h>
#include <math.h>

int main() {
    int K;
    scanf("%d", &K);


    int n = (int)((1 + sqrt(1 + 8 * K)) / 2);

   
    if (n * (n + 1) / 2 < K) {
        n = n + 1;
    }
    if (n >= 1 && (n - 1) * n / 2 >= K) {
        n = n - 1;
    }

    int pos = K - (n - 1) * n / 2;
    int m = pos - 1;

    printf("%d %d\n", m, n);

    return 0;
}