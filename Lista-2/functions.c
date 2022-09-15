#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define SUCESS  (00)

float Average(float a, float b, float c)
{
    return (a + b + c)/3;
}

float WeightedAverage(float a, float b, float c)
{
    return ((a*3 + b*4 + c*5)/12);
}

float Perimeter(float r)
{
    return (2 * M_PI * r);
}

double CircleArea(float r){
    return (M_PI * pow(r,2));
}

float TriangleArea(float b, float h)
{
    return ((b * h)/2);
}

float BoxArea(float a, float b, float c)
{
    return ((a * b) * 2 + (b * c) * 2 + (a * c) * 2);
}

float BoxVolume(float a, float b, float c)
{
    return (a * b * c);
}

double CylinderArea(float r, float h)
{
    return (CircleArea(r) * 2 + Perimeter(r) * h);
}

double CylinderVolume(float r, float h)
{
    return (CircleArea(r) * h);
}

double Hypotenuse(float b, float c)
{
    return (sqrt(pow(b,2) + pow(c,2)));
}

double PositiveRoot(float a, float b, float c)
{
    double delta, deltaSqrt;
    double firstX, secondX;

    delta = pow(b,2) - (4 * a * c);

    if(delta <= 0)
    {
        return -1;
    }

    deltaSqrt = sqrt(delta);
    firstX = ((-1 * b) + deltaSqrt)/(2*a);

    return firstX;
}

int main(int argc, char const *argv[])
{
    printf("\nLista 02 - Testando as funcoes:\n\n");

    printf("Media: %.3f \n", Average(5, 6, 7));
    printf("Media poderada: %.3f \n", WeightedAverage(5, 6, 7));
    printf("Perimetro: %.3f \n", Perimeter(10));
    printf("Area do circulo: %.3lf \n", CircleArea(7));
    printf("Area do triangulo: %.3f \n", TriangleArea(8, 9));
    printf("Area da caixa: %.3f \n", BoxArea(3, 6, 2));
    printf("Volume da caixa: %.3f \n", BoxVolume(3, 6, 2));
    printf("Area do cilindro: %.3f \n", CylinderArea(4, 10));
    printf("Volume do cilindro: %.3f \n", CylinderVolume(4, 10));
    printf("Hipotenusa: %.3f \n", Hypotenuse(3, 4));
    printf("Raiz positiva: %.3f \n", PositiveRoot(10, 2, -15));

    printf("\n");

    return SUCESS;
}