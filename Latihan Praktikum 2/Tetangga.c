#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char grid[101][101];
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int X, Y;
    scanf("%d %d", &X, &Y);

    
    int r = X - 1;
    int c = Y - 1;

    int semua_x = 1; 

   
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            
            
            if (i < 0 || i >= N || j < 0 || j >= M) {
                continue;
            }
            
            
            if (i == r && j == c) {
                continue;
            }
            
            
            if (grid[i][j] != 'x') {
                semua_x = 0;
            }
        }
    }

    if (semua_x == 1) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}