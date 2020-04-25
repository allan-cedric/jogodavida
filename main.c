#include "menu.h"
#include "lista_dupla.h"
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

    /* Tela p/ cada geração / Tela do menu */
    WINDOW *geracao = newwin(36, 169, 3, 0);
    WINDOW *menu = newwin(3, 169, 0, 0);

    /* Listas definidas */
    t_lista geracao_atual;
    t_lista vizinhos;
    t_lista nascimentos;
    inicializa_lista(&geracao_atual);
    inicializa_lista(&vizinhos);
    inicializa_lista(&nascimentos);

    /* Menu completo */
    char ch;
    while (1)
    {
        tamanho_tela();
        wclear(menu);
        titulo(menu, 138);
        interface(geracao, menu, &geracao_atual);

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
    wclear(geracao);
    wclear(menu);
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

    while (!lista_vazia(&geracao_atual))
    {
        /* Impressão da geração atual */
        inicializa_atual_inicio(&geracao_atual);
        while (geracao_atual.atual != geracao_atual.fim)
        {
            consulta_item_atual(&i, &j, &geracao_atual);

            wattron(geracao, A_BOLD);
            wattron(geracao, COLOR_PAIR(1));
            box(geracao, 0, 0);
            wattroff(geracao, COLOR_PAIR(1));

            wattron(geracao, COLOR_PAIR(2));
            mvwaddch(geracao, i, j, 'O');
            wattroff(geracao, COLOR_PAIR(2));
            wattroff(geracao, A_BOLD);

            wrefresh(geracao);
            sleep(1);

            incrementa_atual(&geracao_atual);
        }

        gera_vizinhos(&geracao_atual, &vizinhos);
        dinamica_populacao(&geracao_atual, &vizinhos, &nascimentos);
        concatena_listas(&geracao_atual, &nascimentos);
        destroi_lista(&vizinhos);
        inicializa_lista(&vizinhos);

        wattron(menu, A_BOLD);
        wattron(menu, COLOR_PAIR(3));
        mvwprintw(menu, 1, 120, "Pressione S p/ sair");
        wattroff(menu, COLOR_PAIR(3));
        wattron(menu, A_BOLD);
        wrefresh(menu);

        ch = wgetch(menu);
        if (ch == 's' || ch == 'S')
            break;
    }

    destroi_lista(&geracao_atual);
    destroi_lista(&vizinhos);
    destroi_lista(&nascimentos);
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