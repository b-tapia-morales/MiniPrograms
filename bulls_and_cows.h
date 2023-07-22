#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 4
#define TRIES 5

void generateRandomNumbers(int *d1, int *d2, int *d3, int *d4);

void countBullsAndCows(int *bulls, int *cows, int *secretNumber, int inplaceDigit, int d1, int d2, int d3);

void generateRandomNumbers(int *d1, int *d2, int *d3, int *d4) {
    *d1 = rand() % 10;
    *d2 = rand() % 10;
    while (*d1 == *d2) {
        *d2 = rand() % 10;
    }
    *d3 = rand() % 10;
    while (*d1 == *d3 || *d2 == *d3) {
        *d3 = rand() % 10;
    }
    *d4 = rand() % 10;
    while (*d1 == *d4 || *d2 == *d4 || *d3 == *d4) {
        *d4 = rand() % 10;
    }
}

void countBullsAndCows(int *bulls, int *cows, int *secretNumber, int inplaceDigit, int d1, int d2, int d3) {
    int digit = *secretNumber % 10;
    if (digit == inplaceDigit) {
        *bulls += 1;
    } else if (digit == d1 || digit == d2 || digit == d3) {
        *cows += 1;
    }
    *secretNumber /= 10;
}

void bullsAndCows() {
    int a, b, c, d;
    generateRandomNumbers(&a, &b, &c, &d);
    printf("El numero es: %d%d%d%d\n", d, c, b, a);
    int i = 1;
    while (i <= TRIES) {
        int bulls = 0, cows = 0;
        int userNumber = 0;
        printf("Ingrese su numero: ");
        scanf("%d", &userNumber);
        countBullsAndCows(&bulls, &cows, &userNumber, a, b, c, d);
        countBullsAndCows(&bulls, &cows, &userNumber, b, a, c, d);
        countBullsAndCows(&bulls, &cows, &userNumber, c, a, b, d);
        countBullsAndCows(&bulls, &cows, &userNumber, d, a, b, c);
        if (bulls == SIZE) {
            printf("Has adivinado el numero!\n");
            return;
        }
        printf("Toques: %d, Famas: %d\n", cows, bulls);
        i++;
    }
    printf("Perdiste! El numero era: %d%d%d%d\n", a, b, c, d);
}
