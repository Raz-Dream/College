#include <stdio.h>
#include <string.h>

void balik_kata(char kata[]) {
    int len = strlen(kata);

    for (int i = len - 1; i >= 0; ) {
        if (i > 0 && (
            (kata[i-1] == 'n' && kata[i] == 'g') ||
            (kata[i-1] == 'n' && kata[i] == 'y') ||
            (kata[i-1] == 'm' && kata[i] == 'b') ||
            (kata[i-1] == 'm' && kata[i] == 'p')
        )) {
            printf("%c%c", kata[i-1], kata[i]);
            i -= 2;
        } else {
            printf("%c", kata[i]);
            i--;
        }
    }
}

int main() {
    char kata[100];

    printf("Masukkan kata: ");
    scanf("%s", kata);

    printf("Hasil: ");
    balik_kata(kata);
    printf("\n");

    return 0;
}