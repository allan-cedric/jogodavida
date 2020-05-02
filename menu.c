#include "menu.h"

void interface(WINDOW *scr, WINDOW *scr2, t_lista *gen, int mat[LIN][COL])
{
    int i, j;

    wattron(scr, A_BOLD);
    wattron(scr2, A_BOLD);

    /* Borda da área das gerações */
    wattron(scr, COLOR_PAIR(1));
    box(scr, 0, 0);
    wattroff(scr, COLOR_PAIR(1));
    wrefresh(scr);

    /* Borda da área de menu */
    wattron(scr2, COLOR_PAIR(3));
    box(scr2, 0, 0);
    wattroff(scr2, COLOR_PAIR(3));
    wrefresh(scr2);

    /* Input formatado da posição */
    mvwprintw(scr2, 1, 2, "Escolha uma posição que vai de (1,1) até (34,167). (Ex.: 2 10) : ");
    mvwscanw(scr2, 1, 70, "%i %i", &i, &j);
    wrefresh(scr2);

    /* Impressão de uma célula na geração inicial */
    if (i >= 1 && i < LIN)
    {
        if (j >= 1 && j < COL)
        {
            insere_inicio_lista(i, j, VIVO, gen);
            mat[i][j] = VIVO;
            wattron(scr, COLOR_PAIR(2));
            mvwaddch(scr, i, j, 'O');
            wattroff(scr, COLOR_PAIR(2));
            wrefresh(scr);
        }
    }

    wattroff(scr, A_BOLD);
    wattroff(scr2, A_BOLD);
}

void titulo(WINDOW *scr, int pos)
{
    wattron(scr, A_BOLD);
    wattron(scr, COLOR_PAIR(5));
    mvwprintw(scr, 1, pos, "JOGO DA VIDA, DE JOHN CONWAY");
    wattron(scr, COLOR_PAIR(5));
    wattroff(scr, A_BOLD);
    wrefresh(scr);
}