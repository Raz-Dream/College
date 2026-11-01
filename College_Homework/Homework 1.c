#include <stdio.h>
#include <stdbool.h>


bool prima(int angka) {
    int i;
    
    if (angka <= 1) {
        return false;
    }
    
    for (i = 2; i * i <= angka; i++) {
        if (angka % i == 0) {
            return false; 
        }
    }
    return true;
}

int main() {
    int batas;
    int i;
    int ujung;
    
    int total[10] = {0}; 

    printf("Masukkan angka prima\n");
    scanf("%d", &batas);
   

    for (i = 2; i <= batas; i++) {
        if (prima(i)) {
           
            ujung = i % 10;
            
           
            total[ujung]++;
        }
    }

    printf("Total Angka Belakang prima:\n");
    
    
    for (i = 0; i < 10; i++) {
       
        if (total[i] > 0) {
            printf("Angka Belakang %d ada %d\n", i, total[i]);
           
        }
    }

    return 0;
} 