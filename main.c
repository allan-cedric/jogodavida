#include "menu.h"
#include <stdlib.h>
#include <unistd.h>

/* Verifica se o tamanho da tela do terminal está apropriada p/ simulação */
void tamanho_tela();

int main()
{
    initscr();

    /* Sistema de cores */
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

    /* Tela p/ cada geração & Tela do menu */
    WINDOW *geracao = newwin(36, 169, 3, 0);
    WINDOW *menu = newwin(3, 169, 0, 0);

    /* Matriz das gerações */
    int mat_geracao[LIN][COL];
    int mat_geracao_calc[LIN][COL];
    inicializa_matriz_geracao(mat_geracao);
    inicializa_matriz_geracao(mat_geracao);

    /* Menu completo */
    char ch;
    while (1)
    {
        tamanho_tela();
        wclear(menu);
        titulo(menu, 138);
        interface(geracao, menu, mat_geracao);

        /* Input formatado para iniciar */
        wattron(menu, A_BLINK);
        wattron(menu, A_BOLD);
        wattron(menu, COLOR_PAIR(4));
        mvwprintw(menu, 1, 80, "Envie G para começar! ");
        wattroff(menu, COLOR_PAIR(4));
        wattroff(menu, A_BOLD);
        wattroff(menu, A_BLINK);
        wrefresh(menu);
        ch = wgetch(menu);
        if (ch == 'g' || ch == 'G')
            break;
    }

    /* Cabeçalho que vai ficar durante a simulação */
    wclear(menu);
    wclear(geracao);
    titulo(menu, 70);
    wattron(menu, COLOR_PAIR(3));
    box(menu, 0, 0);
    wattroff(menu, COLOR_PAIR(3));
    wrefresh(menu);

    /* Simulação do Jogo da Vida */
    noecho();
    cbreak();
    nodelay(menu, 1);
    curs_set(0);

    int i, j;
    while (!geracao_morta(mat_geracao))
    {
        wclear(geracao);

        wattron(geracao, COLOR_PAIR(1));
        box(geracao, 0, 0);
        wattroff(geracao, COLOR_PAIR(1));
        wrefresh(geracao);

        wattron(geracao, A_BOLD);
        wattron(geracao, COLOR_PAIR(2));
        for (i = 1; i < LIN; i++)
        {
            for (j = 1; j < COL; j++)
            {
                if (mat_geracao[i][j])
                    mvwaddch(geracao, i, j, 'O');
            }
        }
        wattroff(geracao, A_BOLD);
        wattroff(geracao, COLOR_PAIR(2));
        wrefresh(geracao);

        usleep(100000);

        nova_geracao(mat_geracao, mat_geracao_calc);
        if (geracao_igual(mat_geracao, mat_geracao_calc))
            break;
        copia_matriz(mat_geracao_calc, mat_geracao);
    }
    sleep(1);

    delwin(menu);
    delwin(geracao);
    delwin(stdscr);

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