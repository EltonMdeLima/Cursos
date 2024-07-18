#include <stdio.h>

int main() {

    int num = 9;

    if (num % 2 == 0) {
        printf("%d é par\n", num);
    } else {
        printf("%d é ímpar\n", num);
    }

    switch (num) {
        case 10:
            printf("Número é 10\n");
            break;
        default:
            printf("Número não é 10\n");
    }
    return 0;
}