#include <math.h>
#include <stdio.h>
#include <string.h>

#define BASE2 31

void binToDec() {
    char base2[BASE2] = {0};
    printf("Ingrese un numero en base binaria: ");
    scanf("%31s", base2);
    int i = 0;
    int n = (int) strlen(base2);
    int base10 = 0;
    while (i < n) {
        int digit = base2[i] - '0';
        base10 += digit * (int) pow(2, n - (i + 1));
        i++;
    }
    printf("La representacion decimal del numero es: %d\n", base10);
    getchar();
}

void decToBin() {
    int base10 = 0;
    printf("Ingrese un numero en base decimal: ");
    scanf("%d", &base10);
    int i = 0;
    int n = (int) floor(log2(base10)) + 1;
    char base2[n];
    while (i < n) {
        int remainder = base10 % 2;
        base2[n - (i + 1)] = remainder + '0';
        base10 /= 2;
        i++;
    }
    printf("La representacion binaria del numero es: %.*s\n", n, base2);
    getchar();
}
