#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS (00)

int fat(int n) 
{
    return (n == 0) ? 1 : n * fat(n - 1);
}

int mdc(int a, int b) 
{
    return (b == 0) ? a : mdc(b, a % b);
}   

int mdc3(int a, int b, int c) 
{
    return mdc(mdc(a, b), c);
}

int fib(int n) 
{
    return (n == 0 || n == 1) ? 1 : fib(n - 1) + fib(n - 2);
}

int primo(int n, int i) 
{
    return (i == 1) ? 1 : (n % i == 0) ? 0 : primo(n, i - 1);
}

void descrescente(int n)
{
    if (n > 0) 
    {
        printf("%d ", n);
        descrescente(n - 1);
    }

    if (n == 0)
        printf("\n");
}

float resto(float a, float b)
{
    return (a < b) ? a : resto(a - b, b);
}

int form(int n)
{
    return (n == 1) ? 1 : (n * n + form(n - 1));
}

int mmc(int a, int b)
{
    return (a * b) / mdc(a, b);
}

float mydiv(float a, float b)
{
    return (a < b) ? 0 : 1 + mydiv(a - b, b);
}

float raiz(float n, float chute)
{
    float chuteQuadrado = chute * chute;

    if (chuteQuadrado < n + 0.001 && chuteQuadrado > n - 0.001)
        return chute;
    
    if (chuteQuadrado > n)
        return raiz(n, chute * 0.5);

    if (chuteQuadrado < n)
        return raiz(n, chute * 1.5);
}

int dig(int n)
{
    return (n < 10) ? n : n % 10 + dig(n / 10);
}

int myexp(int a, int b)
{
    return (b == 0) ? 1 : a * myexp(a, b - 1);
}

int crescente(int n)
{
    if (n > 0)
    {
        crescente(n - 1);
        printf("%d ", n);
    }

    if (n == 0)
        printf("\n");
}

int main(int argc, char const *argv[])
{
    float decimal1, decimal2;
    int integer1, integer2, integer3;

    printf("\n Lista de exercicios 04: Funcoes recursivas \n\n");

    printf(" A. Funcao recursiva para calcular o fatorial de um numero inteiro: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" O fatorial de %d e %d \n\n", integer1, fat(integer1));

    printf(" B. Funcao recursiva para calcular o MDC de dois numeros inteiros: \n");
    printf(" Digite dois numeros inteiros: ");
    scanf("%d %d", &integer1, &integer2);
    printf(" O MDC de %d e %d e %d \n\n", integer1, integer2, mdc(integer1, integer2));

    printf(" C. Funcao recursiva para calcular o MDC de tres numeros inteiros: \n");
    printf(" Digite tres numeros inteiros: ");
    scanf("%d %d %d", &integer1, &integer2, &integer3);
    printf(" O MDC de %d, %d e %d e %d \n\n", integer1, integer2, integer3, mdc3(integer1, integer2, integer3));

    printf(" D. Funcao recursiva para calcular o n-esimo termo da sequencia de Fibonacci: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" O %d-esimo termo da sequencia de Fibonacci e %d \n\n", integer1, fib(integer1));

    printf(" E. Funcao recursiva para verificar se um numero inteiro e primo: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" O numero %d %s primo \n\n", integer1, primo(integer1, integer1 - 1) ? "e" : "nao e");

    printf(" F. Funcao recursiva para imprimir os numeros de 1 a n em ordem decrescente: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" Os numeros de 1 a %d em ordem decrescente sao: ", integer1);
    descrescente(integer1);
    printf("\n");
    
    printf(" G. Funcao recursiva para calcular o resto da divisao de dois numeros reais: \n");
    printf(" Digite dois numeros reais: ");
    scanf("%f %f", &decimal1, &decimal2);
    printf(" O resto da divisao de %f por %f e %f \n\n", decimal1, decimal2, resto(decimal1, decimal2));
    
    printf(" H. Funcao recursiva para calcular a soma dos n^2 primeiros numeros naturais: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" A soma dos %d primeiros numeros naturais e %d \n\n", integer1, form(integer1));

    printf(" I. Funcao recursiva para calcular o MMC de dois numeros inteiros: \n");
    printf(" Digite dois numeros inteiros: ");
    scanf("%d %d", &integer1, &integer2);
    printf(" O MMC de %d e %d e %d \n\n", integer1, integer2, mmc(integer1, integer2));

    printf(" J. Funcao recursiva para calcular a divisao inteira de dois numeros inteiros: \n");
    printf(" Digite dois numeros decimais: ");
    scanf("%f %f", &decimal1, &decimal2);
    printf(" A divisao inteira de %f por %f e %f \n\n", decimal1, decimal2, mydiv(decimal1, decimal2));

    printf(" L. Funcao recursiva para calcular a raiz quadrada de um numero real: \n");
    printf(" Digite um numero real: ");
    scanf("%f", &decimal1);
    printf(" A raiz quadrada de %f e %f \n\n", decimal1, raiz(decimal1, 1));

    printf(" M. Funcao recursiva para calcular a soma dos digitos de um numero inteiro: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" A soma dos digitos de %d e %d \n\n", integer1, dig(integer1));

    printf(" N. Funcao recursiva para calcular a potencia de um numero inteiro: \n");
    printf(" Digite dois numeros inteiros: ");
    scanf("%d %d", &integer1, &integer2);
    printf(" A potencia de %d elevado a %d e %d \n\n", integer1, integer2, myexp(integer1, integer2));

    printf(" O. Funcao recursiva para imprimir os numeros de 1 a n em ordem crescente: \n");
    printf(" Digite um numero inteiro: ");
    scanf("%d", &integer1);
    printf(" Os numeros de 1 a %d em ordem crescente sao: ", integer1);
    crescente(integer1);
    printf("\n\n");
    
    return SUCCESS;
}
