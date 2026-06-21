#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int main() {
    // ==================== NÍVEL NOVATO ====================
    // Posicionamento dos Navios
    printf("========== NÍVEL NOVATO ==========\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiroNovato[TAMANHO][TAMANHO];
    
    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiroNovato[i][j] = 0;
        }
    }
    
    // Posicionando navio HORIZONTAL: linha 2, colunas 3, 4, 5
    // Cada posição ocupada recebe valor 3
    tabuleiroNovato[2][3] = 3;
    tabuleiroNovato[2][4] = 3;
    tabuleiroNovato[2][5] = 3;
    
    // Posicionando navio VERTICAL: coluna 7, linhas 5, 6, 7
    tabuleiroNovato[5][7] = 3;
    tabuleiroNovato[6][7] = 3;
    tabuleiroNovato[7][7] = 3;
    
    // Exibindo as coordenadas dos navios
    printf("Navio Horizontal: (2,3) (2,4) (2,5)\n");
    printf("Navio Vertical: (5,7) (6,7) (7,7)\n");
    
    // Exibindo o tabuleiro completo
    printf("\nTabuleiro (0 = água, 3 = navio):\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiroNovato[i][j]);
        }
        printf("\n");
    }
    
    // ==================== NÍVEL AVENTUREIRO ====================
    printf("\n========== NÍVEL AVENTUREIRO ==========\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiroAventureiro[TAMANHO][TAMANHO];
    
    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiroAventureiro[i][j] = 0;
        }
    }
    
    // Posicionando 4 navios:
    // 1 - Horizontal: linha 1, colunas 2, 3, 4
    tabuleiroAventureiro[1][2] = 3;
    tabuleiroAventureiro[1][3] = 3;
    tabuleiroAventureiro[1][4] = 3;
    
    // 2 - Vertical: coluna 6, linhas 4, 5, 6
    tabuleiroAventureiro[4][6] = 3;
    tabuleiroAventureiro[5][6] = 3;
    tabuleiroAventureiro[6][6] = 3;
    
    // 3 - Diagonal principal (\): (6,1) (7,2) (8,3)
    tabuleiroAventureiro[6][1] = 3;
    tabuleiroAventureiro[7][2] = 3;
    tabuleiroAventureiro[8][3] = 3;
    
    // 4 - Diagonal secundária (/): (2,8) (3,7) (4,6)
    tabuleiroAventureiro[2][8] = 3;
    tabuleiroAventureiro[3][7] = 3;
    tabuleiroAventureiro[4][6] = 3;
    
    // Exibindo o tabuleiro completo
    printf("Tabuleiro (0 = água, 3 = navio):\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiroAventureiro[i][j]);
        }
        printf("\n");
    }
    
    // ==================== NÍVEL MESTRE ====================
    printf("\n========== NÍVEL MESTRE ==========\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiroMestre[TAMANHO][TAMANHO];
    
    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiroMestre[i][j] = 0;
        }
    }
    
    // Posicionando alguns navios para visualização
    tabuleiroMestre[1][2] = 3;
    tabuleiroMestre[1][3] = 3;
    tabuleiroMestre[1][4] = 3;
    
    tabuleiroMestre[4][6] = 3;
    tabuleiroMestre[5][6] = 3;
    tabuleiroMestre[6][6] = 3;
    
    // ===== HABILIDADE EM CONE =====
    // Matriz 5x5 representando a habilidade em cone
    // O topo do cone está na linha 0, centro coluna 2
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // O cone se expande para baixo: a largura aumenta com a linha
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }
    
    // Exibindo a matriz de habilidade em cone
    printf("\nHabilidade em CONE:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    
    // Aplicando o cone ao tabuleiro (centro na linha 3, coluna 5)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int linha = 3 + i - 2;  // Ajuste para centralizar
                int coluna = 5 + j - 2; // Ajuste para centralizar
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    tabuleiroMestre[linha][coluna] = 5; // 5 representa área afetada pela habilidade
                }
            }
        }
    }
    
    // ===== HABILIDADE EM CRUZ =====
    // Matriz 5x5 representando a habilidade em cruz
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A cruz tem centro na posição (2,2)
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }
    
    // Exibindo a matriz de habilidade em cruz
    printf("\nHabilidade em CRUZ:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    
    // Aplicando a cruz ao tabuleiro (centro na linha 7, coluna 3)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int linha = 7 + i - 2;
                int coluna = 3 + j - 2;
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    tabuleiroMestre[linha][coluna] = 5;
                }
            }
        }
    }
    
    // ===== HABILIDADE EM OCTAEDRO =====
    // Matriz 5x5 representando a habilidade em octaedro (losango)
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância Manhattan do centro (2,2)
            int dist = abs(i - 2) + abs(j - 2);
            if (dist <= 2 && dist % 2 == 0) {
                octaedro[i][j] = 1;
            }
        }
    }
    
    // Exibindo a matriz de habilidade em octaedro
    printf("\nHabilidade em OCTAEDRO:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    
    // Aplicando o octaedro ao tabuleiro (centro na linha 2, coluna 8)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int linha = 2 + i - 2;
                int coluna = 8 + j - 2;
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    tabuleiroMestre[linha][coluna] = 5;
                }
            }
        }
    }
    
    // Exibindo o tabuleiro final com todas as habilidades
    printf("\nTabuleiro Nível Mestre (0 = água, 3 = navio, 5 = habilidade):\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiroMestre[i][j]);
        }
        printf("\n");
    }
    
    printf("\n✅ Desafio Batalha Naval concluído com sucesso!\n");
    
    return 0;
}