#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 4
#define TRIES 5

bool isInArray(int arr[], int x) {
    int i = 0;
    while (i < SIZE) {
        if (x == arr[i]) {
            return true;
        }
        i++;
    }
    return false;
}

void fillArray(int arr[]) {
    int i = 0;
    while (i < SIZE) {
        int digit = rand() % 10;
        while (i > 0 && isInArray(arr, digit)) {
            digit = rand() % 10;
        }
        arr[i] = digit;
        i++;
    }
}

void showArray(int arr[]) {
    int i = SIZE - 1;
    while (i >= 0) {
        printf("%d", arr[i]);
        i--;
    }
    printf("\n");
}

void countBullsAndCowsArr(int *bulls, int *cows, int usrNumber, int cpuNumber[]) {
    for (int i = SIZE - 1; i >= 0; i--) {
        int digit = usrNumber % 10;
        if (digit == cpuNumber[i]) {
            *bulls += 1;
        } else if (isInArray(cpuNumber, digit)) {
            *cows += 1;
        }
        usrNumber /= 10;
    }
}

void bullsAndCowsArr() {
    int cpuNumber[SIZE] = {0};
    fillArray(cpuNumber);
    printf("El numero es: ");
    showArray(cpuNumber);
    int i = 1;
    while (i <= TRIES) {
        int bulls = 0, cows = 0;
        int usrNumber = 0;
        printf("Ingrese su numero: ");
        scanf("%d", &usrNumber);
        countBullsAndCowsArr(&bulls, &cows, usrNumber, cpuNumber);
        if (bulls == SIZE) {
            printf("Has adivinado el numero!\n");
            return;
        }
        printf("Toques: %d, Famas: %d\n", cows, bulls);
        i++;
    }
    printf("Perdiste! El numero era: ");
    showArray(cpuNumber);
}