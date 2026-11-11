#include <stdio.h>

void Permutasi(int n, int hasil[], int pos, int mulai){
    if(pos == n){
        for (int i = 0; i < n; i++){
            if(i > 0) printf(" ");
            printf("%d", hasil[i]);
        }
        printf("\n");
        return;
    }

for (int i = mulai; i <= n; i++){
    hasil[pos] = i;
    Permutasi(n, hasil, pos + 1, i);
    }
}
int main(){
    int n;
    scanf("%d", &n);

    int hasil[n];
    Permutasi(n, hasil, 0, 1);
    return 0;
}
