#include <stdio.h>

int add(int a, int b);

int main() {
    printf("Hello, World!\n");
    int result = add(5, 3);
    printf("The sum is: %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}