#include <stdio.h>
#include <string.h>

void cek_palindrom(char kalimat[]) {
    int kiri = 0;
    int kanan = strlen(kalimat) - 1;
    int palindrom = 1;

    while (kiri < kanan) {
        
        if (kalimat[kiri] == ' ') {
            kiri++;
            continue;
        }
        
        if (kalimat[kanan] == ' ') {
            kanan--;
            continue;
        }

        char c1 = kalimat[kiri];
        char c2 = kalimat[kanan];

        
        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;

        // bandingkan karakter
        if (c1 != c2) {
            palindrom = 0;
            break;
        }
        kiri++;
        kanan--;
    }

    if (palindrom)
        printf("Iya, \"%s\" adalah palindrom\n", kalimat);
    else
        printf("Bukan, \"%s\" bukan palindrom\n", kalimat);
}

int main() {
    char kalimat[200];

    printf("Masukkan kalimat: ");
    scanf(" %[^\n]", kalimat);  

    cek_palindrom(kalimat);

    return 0;
}