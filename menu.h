#ifndef __MENU_H__
#define __MENU_H__

#include <ncurses.h>
#include "jogodavida.h"

/*
    Interface do menu que solicita entrada do usuário
*/
void interface(WINDOW *scr, WINDOW *scr2, int mat[LIN][COL]);

/*
    Interface do menu que ficará durante a simulação
*/
void titulo(WINDOW *scr, int pos);

#endif