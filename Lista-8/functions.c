#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS             (00)
#define ERROR_OPENING_FILE  (-01)
#define MAX_COLUMNS         (100)
#define MAX_ROWS            (100)

void PrintMatriz(float matriz[][MAX_COLUMNS], int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ReadMatriz(float matriz[][MAX_COLUMNS], int* rows, int* columns)
{
    FILE* file = fopen("Files/base_numbers.txt", "r");
    
    if(file == NULL)
    {
        printf("Error opening file.");
        return ERROR_OPENING_FILE;
    }

    fscanf(file, "%d %d", rows, columns);

    for(int i = 0; i < *rows; i++)
    {
        for(int j = 0; j < *columns; j++)
        {
            fscanf(file, "%f", &matriz[i][j]);
        }
    }

    return SUCCESS;
}

float media_matriz(int n, int m, float mat[][100])
{
    float soma = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j =0; j < m; j++)
        {
            soma += mat[i][j];
        }
    }

    return soma / (n * m);
}

/**
 * Elementos da diagonal principal são iguais a 1, demais são zero.
*/
void identidade(int n, float A[][100])
{
    float I[MAX_ROWS][MAX_COLUMNS];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    PrintMatriz(I, n, n);
}

/**
 * Inverte linhas e colunas.
*/
void transposta(int n, float A[][100], float T[][100])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            T[i][j] = A[j][i];
    }
}

bool simetrica(int n, float A[][100])
{
    float T[MAX_ROWS][MAX_COLUMNS];
    transposta(n, A, T);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] != T[i][j])
                return false;
        }
    }

    return true;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j< n; j++)
            S[i][j] = A[i][j] + B[i][j];
    }
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            P[i][j] = 0;
            for(int k = 0; k < n; k++)
                P[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    float matrz[MAX_ROWS][MAX_COLUMNS];
    float T[MAX_ROWS][MAX_COLUMNS];
    float S[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;
    int aux;
    float result;

    printf("\n Exercicios lista 8 - Matrizes: \n\n");

    aux = ReadMatriz(matrz, &rows, &columns);
    if(aux == ERROR_OPENING_FILE)
        return ERROR_OPENING_FILE;
    
    printf("Matriz lida do arquivo: \n");
    PrintMatriz(matrz, rows, columns);

    aux = -1;
    while(aux != 0)
    {
        printf("\nEscolha uma funcionalidade: \n");
        printf("[00] Sair.\n");
        printf("[01] Media dos elementos de uma matriz.\n");
        printf("[02] Imprime a matriz identidade.\n");
        printf("[03] Imprime a matriz transposta.\n");
        printf("[04] Confere se a matriz eh simetrica.\n");
        printf("[05] Soma duas matrizes(a base e a transposta).\n");
        printf("[06] Multiplica duas matrizes.\n");
        printf("Opcao: ");
        scanf("%d", &aux);
        printf("\n");

        switch (aux)
        {
            case 0:
                printf("Encerrando programa.\n\n");
            break;
            case 1:
                result = media_matriz(rows, columns, matrz);
                printf("Media dos elementos da matriz: %.2f\n\n", result);
            break;
            case 2:
                printf("Matriz identidade: \n");
                identidade(rows, matrz);
                printf("\n\n");
            break;
            case 3:
                transposta(rows, matrz, T);
                printf("Matriz transposta: \n");
                PrintMatriz(T, rows, columns);
                printf("\n\n");
            break;
            case 4:
                printf("A matriz base eh simetrica? %s\n\n", simetrica(rows, matrz) ? "Sim" : "Nao");
            break;
            case 5:
                soma_matriz(rows, matrz, T, S);
                printf("Soma das matrizes: \n");
                PrintMatriz(S, rows, columns);
                printf("\n\n");
            break;
            case 6:
                mult_matriz(rows, matrz, T, S);
                printf("Produto das matrizes: \n\n");
                PrintMatriz(S, rows, columns);
                printf("\n");
            break;
            default:
                printf("Escolha invalida. \n");
            break;
        }
    }

    return SUCCESS;
}