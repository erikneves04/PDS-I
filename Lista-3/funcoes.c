#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS	(00)

// Função Auxiliar
bool divisivel(int number, int by)
{
	return (number % by == 0);
}

//QUESTÃO 01
float max(float a, float b, float c)
{
	float ABCompare = (a > b) ? a : b;
	return (ABCompare > c) ? ABCompare : c;
}

float min(float a, float b, float c)
{
	float ABCompare = (a < b) ? a : b;
	return (ABCompare < c) ? ABCompare : c;
}

// QUESTÃO 02
bool par(int number)
{
	return divisivel(number, 2);
}

bool dentro(float x, float y, float z)
{
	return (x >= y) ? (x <= z) : false;
}

bool fora(float x, float y, float z)
{
	return !dentro(x, y, z);
}

// QUESTÃO 03
int bissexto(int year)
{
	return divisivel(year, 400) ? true : (divisivel(year, 4) && !divisivel(year, 100));
}

int main(int argc, char const *argv[])
{
	float x, y, z;
	
	printf("Digite tres numeros para serem usados nas operacoes \n");
	printf("X: ");
	scanf("%f", &x);
	printf("Y: ");
	scanf("%f", &y);
	printf("Z: ");
	scanf("%f", &z);
	
	printf("\nLista 03 - Testando as funções: \n");
	
	printf("\n Questao 01:\n");
	printf("A(max) - %.2f\n", max(x,y,z));
	printf("B(min) - %.2f\n", min(x,y,z));
	
	printf("\n Questao 02: \n");
	printf("A(X eh par) - %d \n", par(x));
	printf("B(dentro) - %d \n", dentro(x,y,z));
	printf("C(fora) - %d \n", fora(x,y,z));
	
	printf("\n Questao 03: \n");
	printf("Eh bissexto: \n");
	printf("Ano: 2000 - Resultado: %d \n", bissexto(2000));
	printf("Ano: 1900 - Resultado: %d \n", bissexto(1900));
	printf("Ano: 3600 - Resultado: %d \n", bissexto(3600));
	printf("Ano: 2004 - Resultado: %d \n", bissexto(2004));

	printf("\n");
	
	return SUCCESS;
}
