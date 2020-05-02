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