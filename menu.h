#ifndef __MENU_H__
#define __MENU_H__

#include <ncurses.h>
#include "lista_dupla.h"

#define MORTO 0
#define VIVO 1

void interface(WINDOW *scr, WINDOW *scr2, t_lista *gen);

void titulo(WINDOW *scr, int pos);

#endif