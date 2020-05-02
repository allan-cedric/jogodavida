#ifndef __JOGODAVIDA_H__
#define __JOGODAVIDA_H__

#define MORTO 0
#define VIVO 1

#define LIN 35
#define COL 168

void inicializa_matriz_geracao(int mat[LIN][COL]);

int posicao_valida(int i, int j);

int geracao_morta(int mat[LIN][COL]);

void nova_geracao(int mat[LIN][COL], int mat_1[LIN][COL]);

void copia_matriz(int mat[LIN][COL], int mat_1[LIN][COL]);

int conta_vizinhos(int i, int j, int mat[LIN][COL]);

#endif