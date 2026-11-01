#include <stdio.h>

void cariTerbesarTerkecil(int A[], int n, int *max, int *min) {
    *max = A[0];
    *min = A[0];
    
    for (int i = 1; i < n; i++) {
        if (A[i] > *max) {
            *max = A[i];
        }
        if (A[i] < *min) {
            *min = A[i];
        }
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    int A[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int max_val, min_val;
    
    cariTerbesarTerkecil(A, n, &max_val, &min_val);
    
    printf("max: %d\n", max_val);
    printf("min: %d\n", min_val);
    
    return 0;
}