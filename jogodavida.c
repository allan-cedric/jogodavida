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

void gera_vizinhos(t_lista *gen, t_lista *viz)
{
    int i, j, i1, j1;
    inicializa_atual_inicio(gen);
    while (gen->atual != gen->fim)
    {
        consulta_item_atual(&i, &j, gen);
        for (i1 = i - 1; i1 <= i; i1++)
        {
            for (j1 = j1 - 1; j <= j; j1++)
            {
                if (!pertence_lista(i1, j1, viz) && !pertence_lista(i1, j1, gen))
                    insere_inicio_lista(i1, j1, MORTO, viz);
            }
        }
        incrementa_atual(gen);
    }
}