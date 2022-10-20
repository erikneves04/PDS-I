#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SUCCESS (00)

bool EhPrimo(int x)
{
    int i;

    if(x <= 1)
        return 0;

    for(i = 2; i < x; i++)
        if(x % i == 0)
            return false;

    return true;
}

void PrintPrimeNumbers()
{
    int count = 0;
    int nNumbers, aux = 2;
    FILE * file = fopen("Files/print_numbers.txt", "w + t");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Digite o numero de primos que deseja imprimir: ");
    scanf("%d", &nNumbers);

    while(count < nNumbers)
    {
        if(EhPrimo(aux))
        {
            fprintf(file, "%d\n", aux);
            count++;
        }

        aux++;
    }

    fclose(file);
}

void ValidatePrimeNumbers()
{
    FILE * base = fopen("Files/base_numbers.txt", "r + t");
    FILE * destiny = fopen("Files/destiny_numbers.txt", "w + t");
    int number;

    while(!feof(base))
    {
        fscanf(base, "%d", &number);
        fprintf(destiny, "%.4d | %12s\n", number, EhPrimo(number) ? "é primo" : "não é primo");
    }

    fclose(base);
    fclose(destiny);
}

void SeparatesPrimeNumbers()
{
    FILE * base = fopen("Files/base_numbers.txt", "r + t");
    FILE * prime = fopen("Files/prime_numbers.txt", "w + t");
    FILE * notPrime = fopen("Files/not_prime_numbers.txt", "w + t");
    int number;
    
    while(!feof(base))
    {
        fscanf(base, "%d", &number);
        if(EhPrimo(number))
            fprintf(prime, "%d\n", number);
        else
            fprintf(notPrime, "%d\n", number);
    }

    fclose(base);
    fclose(prime);
    fclose(notPrime);
}

float Q4Rule(float x)
{
    return pow(x, 2) - 5 * x + 1;
}

void ApplyQ4Rule()
{
    FILE * base = fopen("Files/base_float_numbers.txt", "r + t");
    FILE * destiny = fopen("Files/destiny_q4_numbers.txt", "w + t");
    float number;

    fprintf(destiny, "  x  | f(x)\n");
    while(!feof(base))
    {
        fscanf(base, "%f", &number);
        fprintf(destiny, " %.3f | %.3f\n", number, Q4Rule(number));
    }

    fclose(base);
    fclose(destiny);
}

float Q5Rule(float x, float a, float b, float c, float d)
{
    return pow((a * x), 3) + pow((b * x), 2) + (c * x) + d;
}

void ApplyQ5Rule()
{
    FILE * base = fopen("Files/base_float_numbers.txt", "r + t");
    FILE * destiny = fopen("Files/destiny_q5_numbers.txt", "w + t");
    float a, b, c, d;
    float number;

    printf("Digite os valores para a, b, c e d: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    fprintf(destiny, "  x  | f(x)\n");
    while(!feof(base))
    {
        fscanf(base, "%f", &number);
        fprintf(destiny, " %.3f | %.3f\n", number, Q5Rule(number, a, b, c, d));
    }

    fclose(base);
    fclose(destiny);
}

int main(int argc, char const *argv[])
{
    int option = -1;
    printf("\n Exercicios lista 6 - Arquivos: \n");

    while(option != 0)
    {
        printf("\nEscolha uma funcionalidade: \n");
        printf("[00] Sair.\n");
        printf("[01] Imprimir numeros primos em um arquivo.\n");
        printf("[02] Validar numeros primos em um arquivo.\n");
        printf("[03] Separar numeros primos de nao primos em arquivos diferentes.\n");
        printf("[04] Aplicar regra da questao 4 em um arquivo.\n");
        printf("[05] Aplicar regra da questao 5 em um arquivo.\n");
        printf("Opcao: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
            case 0:
                printf("Encerrando programa.\n\n");
            break;
            case 1:
                PrintPrimeNumbers();
            break;
            case 2:
                ValidatePrimeNumbers();
            break;
            case 3:
                SeparatesPrimeNumbers();
            break;
            case 4:
                ApplyQ4Rule();
            break;
            case 5:
                ApplyQ5Rule();
            break;
            default:
                printf("Escolha invalida. \n");
            break;
        }
    }

    return SUCCESS;
}