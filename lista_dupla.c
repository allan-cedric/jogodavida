/* 
  Source file : 'lista_dupla.c'
  Escrito por : Allan Cedric G.B. Alves da Silva
  Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
  GRR : 20190351
*/

#include "lista_dupla.h"

int inicializa_lista(t_lista *l)
{
	t_nodo *sent_ini, *sent_fim;

	sent_ini = (t_nodo *)malloc(sizeof(t_nodo));
	sent_fim = (t_nodo *)malloc(sizeof(t_nodo));

	if (!sent_ini || !sent_fim)
		return 0;

	l->ini = sent_ini;
	l->fim = sent_fim;

	sent_ini->prev = NULL;
	sent_ini->prox = sent_fim;

	sent_fim->prev = sent_ini;
	sent_fim->prox = NULL;

	l->atual = NULL;
	l->tamanho = 0;

	return 1;
}

int lista_vazia(t_lista *l)
{
	return (l->ini->prox == l->fim);
}

int lista_destruida(t_lista *l)
{
	return (l->ini == NULL);
}

void tamanho_lista(int *tam, t_lista *l)
{
	*tam = l->tamanho;
}

int inicializa_atual_inicio(t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;
	l->atual = l->ini->prox;
	return 1;
}

int inicializa_atual_fim(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;
	l->atual = l->fim->prev;
	return 1;
}

void incrementa_atual(t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return;

	if (l->atual == l->fim)
		l->atual = NULL;
	else
		l->atual = l->atual->prox;
}

void decrementa_atual(t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return;

	if (l->atual == l->ini)
		l->atual = NULL;
	else
		l->atual = l->atual->prev;
}

int consulta_item_atual(int *i, int *j, t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	*i = l->atual->i;
	*j = l->atual->j;
	return 1;
}

int remove_item_atual(int *i, int *j, t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	t_nodo *aux;

	aux = l->atual;

	*i = l->atual->i;
	*j = l->atual->j;

	l->atual->prev->prox = l->atual->prox;
	l->atual->prox->prev = l->atual->prev;

	incrementa_atual(l);

	l->tamanho--;

	free(aux);

	return 1;
}

int insere_inicio_lista(int i, int j, t_lista *l)
{
	if (lista_destruida(l))
		return 0;

	t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (!elemento)
		return 0;

	elemento->i = i;
	elemento->j = j;
	elemento->prev = l->ini;
	elemento->prox = l->ini->prox;

	l->ini->prox->prev = elemento;
	l->ini->prox = elemento;

	l->tamanho++;

	return 1;
}

int insere_fim_lista(int i, int j, t_lista *l)
{
	if (lista_destruida(l))
		return 0;

	t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (!elemento)
		return 0;

	elemento->i = i;
	elemento->j = j;
	elemento->prev = l->fim->prev;
	elemento->prox = l->fim;

	l->fim->prev->prox = elemento;
	l->fim->prev = elemento;

	l->tamanho++;

	return 1;
}

int remove_inicio_lista(int *i, int *j, t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	inicializa_atual_inicio(l);
	*i = l->atual->i;
	*j = l->atual->j;

	l->ini->prox = l->atual->prox;
	l->atual->prox->prev = l->ini;

	free(l->atual);

	l->tamanho--;

	return 1;
}

int remove_fim_lista(int *i, int *j, t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	inicializa_atual_fim(l);
	*i = l->atual->i;
	*j = l->atual->j;

	l->atual->prox->prev = l->atual->prev;
	l->atual->prev->prox = l->fim;

	free(l->atual);

	l->tamanho--;

	return 1;
}

int pertence_lista(int i, int j, t_lista *l)
{
	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	inicializa_atual_inicio(l);

	l->fim->i = i;
	l->fim->j = j;

	while (l->atual->i != i || l->atual->j != j)
		incrementa_atual(l);

	return (l->atual != l->fim);
}

void destroi_lista(t_lista *l)
{
	if (lista_destruida(l))
		return;

	int i, j;
	while (!lista_vazia(l))
		remove_inicio_lista(&i, &j, l);

	free(l->ini);
	free(l->fim);
}
