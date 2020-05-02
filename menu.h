#ifndef __MENU_H__
#define __MENU_H__

#include <ncurses.h>
#include "lista_dupla.h"
#include "jogodavida.h"

void interface(WINDOW *scr, WINDOW *scr2, t_lista *gen, int mat[LIN][COL]);

void titulo(WINDOW *scr, int pos);

#endif