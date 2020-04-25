#include "menu.h"
#include <stdlib.h>
#include <unistd.h>

void tamanho_tela();

int main()
{
    initscr();

    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_GREEN, 0, 999, 0);
    init_color(COLOR_BLUE, 0, 0, 999);
    init_color(COLOR_WHITE, 999, 999, 999);
    init_color(COLOR_YELLOW, 999, 999, 0);
    init_color(COLOR_RED, 999, 0, 0);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);

    WINDOW *geracao = newwin(36, 169, 3, 0);
    WINDOW *menu = newwin(3, 169, 0, 0);

    char ch;
    while (1)
    {
        tamanho_tela();
        wclear(menu);
        titulo(menu, 138);
        interface(geracao, menu);

        /* Input formatado para iniciar */
        wattron(menu, A_BLINK);
        wattron(menu, A_BOLD);
        wattron(menu, COLOR_PAIR(4));
        mvwprintw(menu, 1, 80, "Envie G para começar! ");
        wrefresh(menu);
        ch = wgetch(menu);
        if (ch == 'g' || ch == 'G')
            break;
        wattroff(menu, COLOR_PAIR(4));
        wattroff(menu, A_BOLD);
        wattroff(menu, A_BLINK);
    }

    endwin();
    return 0;
}

void tamanho_tela()
{
    int lin, col;
    getmaxyx(stdscr, lin, col);
    if (lin < 37 || col < 169)
    {
        endwin();
        printf("Tamanho requisitado: pelo menos 39 linhas por 169 colunas!\n");
        printf("Tamanho atual: %i linhas por %i colunas\n", lin, col);
        exit(1);
    }
}