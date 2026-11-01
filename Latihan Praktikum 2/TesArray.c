#include <stdio.h>

int find_min(int b[], int n);
int find_max(int b[], int n);

int main()
{
    int a[100] = {5, 4, 5, 7, -1};
    int n = 9;
    int i;

    for (i = 0; i < n; i++) {
        printf("[%d] = %d\n", i, a[i]);
    }

    printf("Elemen Terkecil = %d\n", find_min(a, n));
    printf("Elemen Terbesar = %d\n", find_max(a, n));

    return 0;
}

int find_min(int b[], int n)
{
    int i;
    int min = b[0];

    for (i = 1; i < n; i++) {
        if (b[i] < min) {
            min = b[i];
        }
    }
    return min;
}

int find_max(int b[], int n)
{
    int i;
    int max = b[0];

    for (i = 1; i < n; i++) {
        if (b[i] > max) {
            max = b[i];
        }
    }
    return max;
}