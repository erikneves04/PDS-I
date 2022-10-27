#include <stdio.h>
#include <stdlib.h>

#define SUCCESS (00)
#define ERROR_OPENING_FILE (-01)
#define MAX_ARRAY_LENGTH (100)

float ReadNumbers(float* numbers)
{
    int count = 0, i;
    FILE * base = fopen("Files/base_float_numbers.txt", "r");

    if (base == NULL)
    {
        printf("Error opening file.");
        return ERROR_OPENING_FILE;
    }

    fscanf(base, "%f", &numbers[count]);
    while(!feof(base))
    {
        count++;
        fscanf(base, "%f", &numbers[count]);
    }

    fclose(base);

    return count;
}

float Average(float* numbers, int count)
{
    int i = 0;
    float sum = 0;

    for (i = 0; i <= count; i++)
    {
        sum += numbers[i];
    }

    return sum / i;
}

float Variance(float* numbers, int count)
{
    int i = 0;
    float average = Average(numbers, count);
    float sum = 0;

    for (i = 0; i <= count; i++)
    {
        sum += (numbers[i] - average) * (numbers[i] - average);
    }

    return sum / i;
}

float max(float* numbers, int count)
{
    int i;
    float max = numbers[0];

    for(i=0; i<=count; i++)
        if(numbers[i] > max)
            max = numbers[i];

    return max;
}

float min(float* numbers, int count)
{
    int i;
    float min = numbers[0];

    for(i=0; i<=count; i++)
        if(numbers[i] < min)
            min = numbers[i];

    return min;
}

float ScalarProduct(float * first, float* second, int count)
{
    int i;
    float product = 0;

    for(i=0; i<=count; i++)
        product += first[i] * second[i];

    return product;
}

int main(int argc, char const *argv[])
{
    int count, i;
    float numbers[MAX_ARRAY_LENGTH];
    float second[MAX_ARRAY_LENGTH];
    float aux;

    int option = -1;
    printf("\n Exercicios lista 7 - Vetores: \n");

    count = ReadNumbers(numbers);
    if(numbers == NULL || count == ERROR_OPENING_FILE)
        return ERROR_OPENING_FILE;

    while(option != 0)
    {
        printf("\nEscolha uma funcionalidade: \n");
        printf("[00] Sair.\n");
        printf("[01] Calcular a media dos numeros contidos no arquivo.\n");
        printf("[02] Calcular a variancia desses numeros.\n");
        printf("[03] Identificar o numero maximo.\n");
        printf("[04] Identificar o numero minimo.\n");
        printf("[05] Calcular o produto escalar entre dois vetores.\n");
        printf("Opcao: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
            case 0:
                printf("Encerrando programa.\n\n");
            break;
            case 1:
               aux = Average(numbers, count);
                printf("Media: %f\n\n", aux);
            break;
            case 2:
                aux = Variance(numbers, count);
                printf("Variancia: %f\n\n", aux);
            break;
            case 3:
                aux = max(numbers, count);
                printf("Maximo: %f\n\n", aux);
            break;
            case 4:
                aux = min(numbers, count);
                printf("Minimo: %f\n\n", aux);
            break;
            case 5:
                printf("Digite os %d numeros do segundo vetor: \n", (count+1));
                for(i=0; i<=count; i++)
                {
                    printf("Numero %d: ", i+1);
                    scanf("%f", &second[i]);
                }

                aux = ScalarProduct(numbers, second, count);
                printf("Produto escalar: %f\n\n", aux);
            break;
            default:
                printf("Escolha invalida. \n");
            break;
        }
    }

    return SUCCESS;
}