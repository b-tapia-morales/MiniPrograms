#include <string.h>
#include <stdio.h>
#include <math.h>

#ifndef LAST_DIGIT_VERIFIER_H
#define LAST_DIGIT_VERIFIER_H

#endif

#define MAX_LENGTH 8

void copyArray(char src[], int dst[], int n) {
    int i = 0;
    while (i < n) {
        dst[i] = src[i] - '0';
        i++;
    }
}

void getLastDigit() {
    char rut[MAX_LENGTH];
    printf("Ingrese el rut: ");
    scanf("%s", rut);
    int n = strlen(rut);
    int arr[n];
    copyArray(rut, arr, n);
    int sum = 0;
    int i = 0;
    int j = 2;
    while (i < n) {
        sum += j * arr[n - (i + 1)];
        i = i + 1;
        j = j == 7 ? 2 : j + 1;
    }
    int remainder = 11 - sum % 11;
    char lastDigit;
    if (remainder == 11) {
        lastDigit = '0';
    } else if (remainder == 10) {
        lastDigit = 'K';
    } else {
        lastDigit = remainder + '0';
    }
    printf("El rut junto al digito verificador es: %.*s-%c\n", n, rut, lastDigit);
}
