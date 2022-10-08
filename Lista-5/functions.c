#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS (00)

int fat(int n)
{
    int i;
    int fat = 1;

    if(n <= 0)
        return 1;

    for(i = n; i > 1; i--)
        fat *= i;
    
    return fat;
}

int mdc(int a, int b)
{
    int i;
    int mdc = 1;

    for(i = 1; i <= a && i <= b; i++)
        if(a % i == 0 && b % i == 0)
            mdc = i;

    return mdc;
}

int mdc3(int a, int b, int c)
{
    return mdc(mdc(a, b), c);
}

int fibonnaci(int x)
{
    int i;
    int fib = 1;
    int ant = 0;
    int aux;

    for(i = 0; i < x; i++)
    {
        aux = fib;
        fib += ant;
        ant = aux;
    }

    return fib;
}

int EhPrimo(int x)
{
    int i;

    if(x <= 1)
        return 0;

    for(i = 2; i < x; i++)
        if(x % i == 0)
            return false;

    return true;
}

void descrescente(int x)
{
    if(x > 0)
        for(; x > 0; x--)
            printf("%d ", x);
    else
        for(; x < 0; x++)
            printf("%d ", x);

    printf("\n");
}

float res(float a, float b)
{
    for(; a >= b; a -= b);
    return a;
}

int form(int x)
{
    int i;
    int soma = 0;

    for(i = 1; i <= x; i++)
        soma += i * i;

    return soma;
}

int mmc(int a, int b)
{
    int i;
    int mmc = 1;

    for(i = 1; i <= a && i <= b; i++)
        if(a % i == 0 && b % i == 0 && i != 1)
            mmc = i;

    return (a * b) / mmc;
}

int myDiv(int a, int b)
{
    int i;
    int div = 0;

    for(i = 0; i < a; i += b)
        div++;

    return div;
}

float mySqrt(int x)
{
   float quadrado, raiz;

    while(true)
    {
        quadrado = raiz * raiz;
        if(quadrado >= (x - 0.001) && quadrado <= (x + 0.001))
            return raiz;
        else if(quadrado > x)
            raiz *= 0.5;
        else
            raiz *= 1.5;
    }
}

int dig(int x)
{
    int soma = 0;

    while(x > 0)
    {
        soma += x % 10;
        x /= 10;
    }

    return soma;
}

int myExp(int x, int y)
{
    int i;
    int exp = 1;

    for(i = 0; i < y; i++)
        exp *= x;

    return exp;
}

void crescente(int x)
{
    int aux;

    if(x > 0)
        for(aux = 1; aux <= x ; aux++)
            printf("%d ", aux);
    else
        for(aux = x; aux <= 0; aux++)
            printf("%d ", aux);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    float a, b;
    int x, y, z;

    printf("\nLista de exercicios 5 - Estruturas de repeticao: \n\n");

    printf("1 - Digite um numero para saber seu fatorial: ");
    scanf("%d", &x);
    printf("Fatorial de %d: %d\n", x, fat(x));
    
    printf("2 - Digite dois numeros para saber o MDC: ");
    scanf("%d %d", &x, &y);
    printf("MDC de %d e %d: %d\n", x, y, mdc(x, y));

    printf("3 - Digite tres numeros para saber o MDC: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("MDC de %d, %d e %d: %d\n", x, y, z, mdc3(x, y, z));

    printf("4 - Digite um numero para saber o seu numero de Fibonacci: ");
    scanf("%d", &x);
    printf("Fibonacci de %d: %d\n", x, fibonnaci(x));

    printf("5 - Digite um numero para saber se ele e primo: ");
    scanf("%d", &x);
    printf("%d e primo? %s\n", x, (EhPrimo(x) ? "Sim" : "Nao"));

    printf("6 - Digite um numero para saber a sequencia decrescente: ");
    scanf("%d", &x);
    printf("Sequencia decrescente de %d: ", x);
    descrescente(x);

    printf("7 - Digite dois numeros para saber o resto da divisao: ");
    scanf("%f %f", &a, &b);
    printf("Resto da divisao de %.2f por %.2f: %.2f\n", a, b, res(a, b));

    printf("8 - Digite um numero para saber a soma dos quadrados: ");
    scanf("%d", &x);
    printf("Soma dos quadrados de %d: %d\n", x, form(x));

    printf("9 - Digite dois numeros para saber o MMC: ");
    scanf("%d %d", &x, &y);
    printf("MMC de %d e %d: %d\n", x, y, mmc(x, y));

    printf("10 - Digite dois numeros para saber a divisao: ");
    scanf("%d %d", &x, &y);
    printf("Divisao de %d por %d: %d\n", x, y, myDiv(x, y));

    printf("11 - Digite um numero para saber a raiz quadrada: ");
    scanf("%d", &x);
    printf("Raiz quadrada de %d: %.2f\n", x, mySqrt(x));

    printf("12 - Digite um numero para saber a soma de seus digitos: ");
    scanf("%d", &x);
    printf("Quantidade de digitos de %d: %d\n", x, dig(x));

    printf("13 - Digite dois numeros para saber a potencia: ");
    scanf("%d %d", &x, &y);
    printf("%d elevado a %d: %d\n", x, y, myExp(x, y));

    printf("14 - Digite um numero para saber a sequencia crescente: ");
    scanf("%d", &x);
    printf("Sequencia crescente de %d: ", x);
    crescente(x);

    return SUCCESS;
}