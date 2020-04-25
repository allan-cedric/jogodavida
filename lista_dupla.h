/* 
  Header file : 'lista_dupla.h'
  Escrito por : Allan Cedric G.B. Alves da Silva
  Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
  GRR : 20190351
*/

#ifndef __LISTA_DUPLA_H__
#define __LISTA_DUPLA_H__

#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
  int i, j, estado;
  struct t_nodo *prox;
  struct t_nodo *prev;
};
typedef struct t_nodo t_nodo;

struct t_lista
{
  t_nodo *ini;
  t_nodo *atual;
  t_nodo *fim;
  int tamanho;
};
typedef struct t_lista t_lista;

/*
  Cria uma lista vazia. Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int inicializa_lista(t_lista *l);

/*
  Retorna 1 se a lista está vazia, senão 0.
*/
int lista_vazia(t_lista *l);

/*
  Retorna 1 se a lista está destruida, senão 0.
*/
int lista_destruida(t_lista *l);

/*
  Remove todos os elementos da lista, inclusive os sentinelas.
*/
void destroi_lista(t_lista *l);

/*
  Insere as chaves i e j no início da lista.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int insere_inicio_lista(int i, int j, int estado, t_lista *l);

/*
  Retorna o tamanho da lista em *tam.
*/
void tamanho_lista(int *tam, t_lista *l);

/*
  Insere as chaves i e j no final da lista.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int insere_fim_lista(int i, int j, int estado, t_lista *l);

/*
  Remove o primeiro nodo da lista e o retorna as chaves em *i e *j.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int remove_inicio_lista(int *i, int *j, t_lista *l);

/*
  Remove o último nodo da lista e o retorna as chaves em *i e *j.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int remove_fim_lista(int *i, int *j, t_lista *l);

/*
  Retorna 1 se as chaves i e j existem na lista, senão 0.
*/
int pertence_lista(int i, int j, t_lista *l);

/* 
  Inicializa o ponteiro atual para o primeiro nodo da lista.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int inicializa_atual_inicio(t_lista *l);

/* 
  Inicializa o ponteiro atual para o último nodo da lista.
  Retorna 1 se a operação foi bem sucedida, senão 0.
*/
int inicializa_atual_fim(t_lista *l);

/*
  Faz o ponteiro atual apontar para o próximo nodo da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o último, isto é, não 
  tem próximo, retorna NULL.
*/
void incrementa_atual(t_lista *l);

/*
  Faz o ponteiro atual apontar para o nodo anterior da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o primeiro, isto é, não 
  tem anterior, retorna NULL.
*/
void decrementa_atual(t_lista *l);

/*
  Retorna em *i e *j as chaves do nodo apontado pelo ponteiro atual. 
  Se atual não for válido a função retorna zero senão retorna 1.
*/
int consulta_item_atual(int *i, int *j, t_lista *atual);

/*
  Remove o nodo apontado por atual da lista l e o retorna em *i e *j as chaves.
  Faz o atual apontar para o sucessor do nodo removido.
  Retorna 1 se houve sucesso, senão 0.
*/
int remove_item_atual(int *i, int *j, t_lista *l);

/*
  Concatena os elementos da lista c (na mesma ordem) ao final
  da lista l e destroi a lista c.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int concatena_listas(t_lista *l, t_lista *c);

#endif