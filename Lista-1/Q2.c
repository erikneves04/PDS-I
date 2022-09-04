#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCESS  (00)

int main(int argc, char const *argv[])
{
    float a, b, c, d;

    printf("Lista 01 - Questao 02:\n");

    printf("Insira os dados necessarios para visualizar os resultados: \n");
    
    printf("A: ");
    scanf("%f", &a);
    printf("B: ");
    scanf("%f", &b);
    printf("C: ");
    scanf("%f", &c);
    printf("D: ");
    scanf("%f", &d);
    
    printf("\n\n");

    printf("A: %f \n", (a + b));
    printf("B: %f \n", (a/c));
    printf("C: %lf \n", (pow(a,2)));
    printf("D: %f \n", (b * c));
    printf("E: %f \n", (a * b - c));
    printf("F: %f \n", (a + b * c));
    printf("G: %f \n", ((a + b) * c));
    printf("H: %lf \n", (sin(a)));
    printf("I: %lf \n", (sqrt(b)));
    printf("J: %f \n", (a + b + c));
    printf("K: %f \n", (a * b * c));
    printf("L: %f \n", ((a + b + c) / d));
    printf("M: %f \n", ((a + b) * (a - d)));
    printf("N: %f \n", ((b / c) + (a * d)));
    printf("O: %lf \n", (sin(b) + cos(c)));
    printf("P: %lf \n", (log10(a) - log10(c)));
    printf("Q: %lf \n", (log10 (a) + (log10(b) * log10(d) - cos(log10(c)))));
    printf("R: %f \n", ((b + a)/c - (d + a)));
    printf("S: %lf \n", ((cos(d) + sin(c)) * (cos(b) - sin(a))));

    return SUCESS;
}