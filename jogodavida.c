#include "jogodavida.h"

void inicializa_matriz_geracao(int mat[LIN][COL])
{
    int i, j;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
            mat[i][j] = MORTO;
    }
}

int posicao_valida(int i, int j)
{
    if (i >= 1 && i < LIN)
        return (j >= 1 && j < COL);
    return 0;
}

int geracao_morta(int mat[LIN][COL])
{
    int i, j;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
        {
            if (mat[i][j])
                return 0;
        }
    }
    return 1;
}

void nova_geracao(int mat[LIN][COL], int mat_1[LIN][COL])
{
    int i, j;
    int num_vizinhos;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
        {
            num_vizinhos = conta_vizinhos(i, j, mat);
            if (num_vizinhos == 3)
                mat_1[i][j] = VIVO;
            else if (num_vizinhos != 2)
                mat_1[i][j] = MORTO;
            else
                mat_1[i][j] = mat[i][j];
        }
    }
}

void copia_matriz(int mat[LIN][COL], int mat_1[LIN][COL])
{
    int i, j;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
            mat_1[i][j] = mat[i][j];
    }
}

int conta_vizinhos(int i, int j, int mat[LIN][COL])
{
    int k, w, soma = 0;
    for (k = i - 1; k <= i + 1; k++)
    {
        for (w = j - 1; w <= j + 1; w++)
        {
            if (posicao_valida(k, w))
                soma += mat[k][w];
        }
    }
    if (mat[i][j])
        return --soma;
    return soma;
}

int geracao_igual(int mat[LIN][COL], int mat_1[LIN][COL])
{
    int i, j;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
        {
            if (mat[i][j] != mat_1[i][j])
                return 0;
        }
    }
    return 1;
}