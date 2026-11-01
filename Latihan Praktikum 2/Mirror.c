#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
        int matriks[105][105]; 
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matriks[i][j]); 
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                printf("%d", matriks[i][j]); 
                if (j > 0) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    
    
    return 0;
}
