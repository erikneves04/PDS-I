#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCESS  (00)

int main(int argc, char const *argv[])
{
    printf("Lista 01 - Questao 01:\n");

    printf("A: %d \n", (3 + 4));
    printf("B: %d \n", (7/4));
    printf("C: %lf \n", (pow(3,2)));
    printf("D: %f \n", (5.3 * 2.1));
    printf("E: %d \n", (2 * 5 - 2));
    printf("F: %d \n", (2 + 2 * 5));
    printf("G: %d \n", ((2 + 5) * 3));
    printf("H: %lf \n", (sin(3.141502)));
    printf("I: %f \n", (sqrt(5)));
    printf("J: %d \n", (1 + 2 + 3));
    printf("K: %d \n", (1 * 2 * 3));
    printf("L: %f \n", ((1 + 2 + 3) / 3.0));
    printf("M: %d \n", ((2 + 4) * (3 - 1)));
    printf("N: %d \n", ((9 / 3) + (3 * 2)));
    printf("O: %lf \n", (sin(4.5) + cos(3.7)));
    printf("P: %lf \n", (log10(2.3) - log10(3.1)));
    printf("Q: %lf \n", (log10 (7) + (log10(7) * log10(7) - cos(log10(7)))));
    printf("!2: %lf \n", (log10(7) + (log10(7) * log10(7) - cos(log10(7)))));
    printf("R: %f \n", ((10.3 + 8.4)/50.3 - (10.3 + 8.4)));
    printf("S: %lf \n", ((cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8))));
    
    return SUCESS;
}