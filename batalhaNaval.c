#include <stdio.h>

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

    //vermelho
    int linhaVermelho = 1;
    int colunaVermelho = 2;

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaVermelho][colunaVermelho + i] = 3;
        navioVermelho[i] = colunaVermelho + i;
    }

    //azul
    int linhaAzul = 5;
    int colunaAzul = 5;

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaAzul + i][colunaAzul] = 3;
        navioAzul[i] = linhaAzul + i;
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

    //Corpo
    for (int i = 0; i < 10; i++)
    {
        printf("%2d |", i + 1); // Imprime número da linha
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", tabuleiro[i][j]); // Imprime valor (0 = água, 3 = navio)
        }
        printf("\n");
    }

    return 0;
}