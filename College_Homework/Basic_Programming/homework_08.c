#include <stdio.h>

void kombinasi(int n, int hasil[], int pos){
    if(pos == n){
        for (int i = 0; i < n; i++){
            if(i > 0) printf(" ");
            printf("%d", hasil[i]);
        }
        printf("\n");
        return;
    }

for (int i = 1; i <= n; i++){
    hasil[pos] = i;
    kombinasi(n, hasil, pos + 1);
    }
}
int main(){
    int n;
    scanf("%d", &n);

    int hasil[n];
    kombinasi(n, hasil, 0);
    return 0;
}
