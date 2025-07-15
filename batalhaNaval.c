#include <stdio.h>

#define TAMANHO_NAVIO 3
#define CAMPO 3

int main()
{
    int tabuleiro[10][10];

    char tabela[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navioVermelho[3]; // horizontal
    int navioAzul[3];     // vertical

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicao dos Navios

    // vermelho
    int linhaVermelho = 1;
    int colunaVermelho = 2;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linhaVermelho][colunaVermelho + i] = CAMPO;

    }

    // azul
    int linhaAzul = 5;
    int colunaAzul = 5;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
           tabuleiro[linhaAzul + i][colunaAzul] = CAMPO;

    }

    int linhaDiagonalVermelha = 0;
    int colunaDiagonalVermelha = 0;

    // Navio Vermelho Diagonal
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linhaDiagonalVermelha + i][colunaDiagonalVermelha + i] == 0)
        {
            tabuleiro[linhaDiagonalVermelha + i][colunaDiagonalVermelha + i] = CAMPO;
        }
    }

    int linhaDiagonalAzul = 2;
    int colunaDiagonalAzul = 9;

    // Navio Azul diagonal
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linhaDiagonalAzul + i][colunaDiagonalAzul - i] == 0)
        {
            tabuleiro[linhaDiagonalAzul + i][colunaDiagonalAzul - i] = CAMPO;
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval \n");

    // Exibição do tabuleiro formatado
    printf("    ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", tabela[i]); // Imprime letras das colunas
    }
    printf("\n");

    // Corpo
    for (int i = 0; i < 10; i++)
    {
        printf("%2d |", i + 1); // Imprime número da linha
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", tabuleiro[i][j]); // Imprime valor 0 = água, 3 = navio)
        }
        printf("\n");
    }

    return 0;
}