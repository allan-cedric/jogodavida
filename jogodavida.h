#ifndef __JOGODAVIDA_H__
#define __JOGODAVIDA_H__

#include <ncurses.h>
#include "lista_dupla.h"

#define MORTO 0
#define VIVO 1

#define LIN 35
#define COL 168

void inicializa_matriz_geracao(int mat[LIN][COL]);

void gera_vizinhos(t_lista *gen, t_lista *viz);

#endif