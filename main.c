#include <stdio.h>
#include <ctype.h>
#include "last_digit_verifier.h"
#include "binary_converter.h"
#include "hexadecimal_converter.h"
#include "bulls_and_cows.h"

void showMenu();

int readInt(char *, int, int);

char readConfirmation(char *);

int readInt(char *message, int lowerBound, int upperBound) {
    while (true) {
        fflush(stdin);
        int value;
        printf("%s [%d, %d]: ", message, lowerBound, upperBound);
        scanf("%d", &value);
        if (value >= lowerBound && value <= upperBound) {
            return value;
        } else {
            printf("El entero ingresado no está en el rango especificado. Intente nuevamente.\n");
        }
    }
}

char readConfirmation(char *message) {
    while (true) {
        fflush(stdin);
        char value;
        printf("%s <'s': si, 'n': no>: ", message);
        scanf("%c", &value);
        if (tolower(value) == 's' || tolower(value) == 'n') {
            return value;
        } else {
            printf("El caracter ingresado no es un caracter de confirmacion valido. Intente nuevamente.\n");
        }
    }
}

void showMenu() {
    printf("1. - Verificador de ultimo digito de rut\n");
    printf("2. - Binario a decimal\n");
    printf("3. - Decimal a binario\n");
    printf("4. - Hexadecimal a decimal\n");
    printf("5. - Decimal a hexadecimal\n");
    printf("6. - Toque y fama\n");
}

int main() {
    while (true) {
        showMenu();
        int option = readInt("Ingrese su opcion", 1, 6);
        if (option == 1) {
            getLastDigit();
        } else if (option == 2) {
            binToDec();
        } else if (option == 3) {
            decToBin();
        } else if (option == 4) {
            hexToDec();
        } else if (option == 5) {
            decToHex();
        } else if (option == 6) {
            bullsAndCows();
        }
        char confirmation = readConfirmation("Desea ejecutar otro programa?");
        if (confirmation == 'n') {
            return 0;
        }
    }
}
