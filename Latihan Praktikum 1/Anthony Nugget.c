#include <stdio.h>

int main() {
    int X, Y;
    char O;

    
    scanf("%d %c %d", &X, &O, &Y);

   
    if (X == Y) {
        X = 0;
    } 
    else {
        
        int bisa_dibagi = (Y != 0 && X % Y == 0) || (X != 0 && Y % X == 0);

        if (bisa_dibagi) {
          
            if (X < Y) {
                X = -X;
            } else {
                Y = -Y;
            }
        }
    }

    float hasil = 0.0;

    
    switch (O) {
        case '+':
            hasil = (float)(X + Y);
            break;
        case '-':
            hasil = (float)(X - Y);
            break;
        case '*':
            hasil = (float)(X * Y);
            break;
        case '/':
           
            hasil = (float)X / Y;
            break;
        default:
            break;
    }


    printf("%.2f\n", hasil);

    return 0;
}