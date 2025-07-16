#include <stdio.h>

#define TAMANHO_NAVIO 3
#define CAMPO 3
#define HAB 5 // Tamanho da matriz de habilidade (cone, cruz, octaedro)
#define AFETADO 5

// matriz cone
void matrizCone(int cone[HAB][HAB])
{
    for (int i = 0; i < HAB; i++)
    {
        for (int j = 0; j < HAB; j++)
        {
            if (i < 3)
            { // Limita altura a 3
                if (j >= (HAB / 2 - i) && j <= (HAB / 2 + i))
                {
                    cone[i][j] = 1;
                }
                else
                {
                    cone[i][j] = 0;
                }
            }
            else
            {
                cone[i][j] = 0; // fora do cone
            }
        }
    }
}

// matriz de cruz
void matrizCruz(int cruz[HAB][HAB])
{
    for (int i = 0; i < HAB; i++)
    {
        for (int j = 0; j < HAB; j++)
        {
            if (i == HAB / 2 || j == HAB / 2)
            {
                cruz[i][j] = 1;
            }
            else
            {
                cruz[i][j] = 0;
            }
        }
    }
}

// Matriz octaedro
void matrizOctaedro(int octaedro[HAB][HAB])
{
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++)
    {
        for (int j = 0; j < HAB; j++)
        {
            int distI = (i < centro) ? centro - i : i - centro;
            int distJ = (j < centro) ? centro - j : j - centro;
            if ((distI + distJ) <= centro)
            {
                octaedro[i][j] = 1;
            }
            else
            {
                octaedro[i][j] = 0;
            }
        }
    }
}

// matriz de habilidade
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[HAB][HAB], int origemLinha, int origemColuna)
{
    for (int i = 0; i < HAB; i++)
    {
        for (int j = 0; j < HAB; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int lin = origemLinha - HAB / 2 + i;
                int col = origemColuna - HAB / 2 + j;
                if (lin >= 0 && lin < 10 && col >= 0 && col < 10)
                {
                    if (tabuleiro[lin][col] != CAMPO)
                    {
                        tabuleiro[lin][col] = AFETADO;
                    }
                }
            }
        }
    }
}

// Função para exibir uma matriz de habilidade
void exibeHabilidade(char *nome, int matriz[HAB][HAB])
{
    printf("\n%s:\n", nome);
    for (int i = 0; i < HAB; i++)
    {
        for (int j = 0; j < HAB; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int tabuleiro[10][10];
    char tabela[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navioVermelho[3]; // horizontal
    int navioAzul[3];     // vertical

    // Matrizes de habilidades
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Posiciona os navios
    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[1][2 + i] = CAMPO; // vermelho horizontal

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[5 + i][5] = CAMPO; // azul vertical

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[i][i] = CAMPO; // diagonal vermelho

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[2 + i][9 - i] = CAMPO; // diagonal azul

    // Construção das habilidades
    matrizCone(cone);
    matrizCruz(cruz);
    matrizOctaedro(octaedro);

    // TESTANDO A EXIBIÇÃO NOS FORMATOS
    exibeHabilidade("CONE", cone);
    exibeHabilidade("CRUZ", cruz);
    exibeHabilidade("OCTAEDRO", octaedro);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 2);     // CONE
    aplicarHabilidade(tabuleiro, cruz, 6, 6);     // CRUZ
    aplicarHabilidade(tabuleiro, octaedro, 8, 8); // OCTAEDRO

    printf("\n>>>>>>>Tabuleiro Batalha Naval<<<<<<<\n\n    ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", tabela[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d |", i + 1);
        for (int j = 0; j < 10; j++)
        {
            if (tabuleiro[i][j] == 0)
                printf(" a ");
            else if (tabuleiro[i][j] == CAMPO)
                printf(" N ");
            else if (tabuleiro[i][j] == AFETADO)
                printf(" x ");
        }
        printf("\n");
    }

    return 0;
}
