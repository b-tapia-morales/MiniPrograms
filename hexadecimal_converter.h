#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef HEXADECIMAL_TO_DECIMAL_H
#define HEXADECIMAL_TO_DECIMAL_H

#endif

#define BASE16 8

void hexToDec() {
    char base16[BASE16] = {0};
    printf("Ingrese un numero en base hexadecimal: ");
    scanf("%8s", base16);
    int n = (int) strlen(base16);
    int i = n - 1;
    int base10 = 0;
    while (i >= 0) {
        int digit = base16[i] >= '0' && base16[i] <= '9' ? base16[i] - '0' : (base16[i] - 'A') + 10;
        base10 += digit * (int) pow(16, n - (i + 1));
        i--;
    }
    printf("La representacion decimal del numero es: %d\n", base10);
    getchar();
}

void decToHex() {
    int base10 = 0;
    printf("Ingrese un numero en base decimal: ");
    scanf("%d", &base10);
    // Se determina cuántos dígitos tendrá la representación binaria del número decimal.
    // C no tiene implementada de manera nativa la función logb(x), con 'b' siendo la base. No obstante, disponemos
    // de la propiedad matemática equivalente: logb(x) = log(x) / log(b)
    int n = (int) trunc(log(base10) / log(16)) + 1;
    // Se declara un arreglo de tamaño igual a la cantidad de dígitos que tiene el número decimal.
    char base16[n];
    // Se ejecuta este ciclo hasta que no sea posible seguir dividiendo en 16 el número decimal (es decir, hasta que
    // se hayan extraído todos sus dígitos).
    int i = 0;
    while (base10 > 0) {
        int remainder = base10 % 16;

        // Caso 1: Si el dígito está en el rango x ∈ [0, 9], se debe realizar una conversión de 'int' a 'char', y el
        // dígito resultante seguirá siendo un entero.
        // La conversión es la misma que en el caso decimal a binario: x + '0'.
        // Ejemplos:
        // x = 5 ⇒ r = x % 16 = 5 % 16 = 5 ⇒ c = '5'
        // x = 9 ⇒ r = x % 16 = 9 % 16 = 9 ⇒ c = '9'

        // Caso 2: Si el dígito está en el rango x ∈ [10, 15], se debe realizar una conversión de 'int' a 'char', pero
        // el dígito resultante ya no será un entero, sino que será un caracter.
        // La conversión es un poco más compleja en este caso: empezamos por sacar únicamente el último dígito a
        // x ∈ [10, 15]. Partiendo desde el caracter 'A', se le suma el resto para obtener los dígitos
        // hexadecimales desde 'A' hasta 'F'.
        // Ejemplos:
        // x = 10 ⇒ r = x % 10 = 10 % 10 = 0 ⇒ hex = 'A' + r = 'A' + 0 = 'A'.
        // x = 12 ⇒ r = x % 10 = 12 % 10 = 2 ⇒ hex = 'A' + r = 'A' + 2 = 'C'.
        // x = 15 ⇒ r = x % 10 = 15 % 10 = 5 ⇒ hex = 'A' + r = 'A' + 5 = 'F'.

        // Revisar tabla de conversión ASCII (entero a caracter y viceversa): https://elcodigoascii.com.ar/
        base16[n - (i + 1)] = remainder >= 0 && remainder <= 9 ? '0' + remainder : 'A' + (remainder % 10);
        base10 /= 16;
        i++;
    }
    printf("La representacion hexadecimal del numero es: %.*s\n", n, base16);
    getchar();
}