#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define SUCESS  (00)

int main(int argc, char const *argv[])
{
    float a, b, c;
    double delta, deltaSqrt;

    printf("Lista 01 - Questao 03:\n\n");

    printf("Insira os dados necessarios para visualizar os resultados: \n");
    
    printf("Primeiro numero: ");
    scanf("%f", &a);
    printf("Segundo numero: ");
    scanf("%f", &b);
    printf("Terceiro numero: ");
    scanf("%f", &c);

    printf("\n");

    printf("A: %f \n", (a + b + c)/3);//
    printf("B: %f \n", (a*3 + b*4 + c*5)/12);
    printf("C: %f \n", (2 * M_PI * a)); //
    printf("D: %lf \n", (M_PI * pow(a,2)));//
    printf("E: %f \n", ((b * c)/2));//
    printf("F: %lf \n", (sqrt(pow(b,2) + pow(c,2))));//

    printf("\nG - Solucao da equacao %.1fX^2 + %.1fX + %.1f : \n", a, b, c);

    delta = pow(b,2) - (4 * a * c);
    if(delta >= 0)
    {
        deltaSqrt = sqrt(delta);

        printf("X': %.3lf \n", ((-1 * b) + deltaSqrt)/(2*a));
        printf("X'': %.3lf \n", ((-1 * b) - deltaSqrt)/(2*a));
    }
    else
    {
        printf("A equacao inserida nao possui solucoes em R. \n");
        printf("Valor de delta: %.lf \n", delta);
    }

    return SUCESS;
}