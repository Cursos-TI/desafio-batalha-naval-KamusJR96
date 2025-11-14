// Inclui a biblioteca padrão de Entrada/Saída (para usar printf)
#include <stdio.h>

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    
    // --- 1. Representação e Inicialização do Tabuleiro ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int sobreposicao = 0; // Variável auxiliar para validação

    // Preenche todo o tabuleiro com ÁGUA (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    /*
     * --- 2. Definições dos Navios (Hardcoded) ---
     * Você pode alterar esses valores para testar diferentes posições.
     * (L = Linha, C = Coluna)
     */
    
    // Navio 1: Horizontal (Ocupará [1][1], [1][2], [1][3])
    int nav1_H_L = 1;
    int nav1_H_C = 1;

    // Navio 2: Vertical (Ocupará [3][8], [4][8], [5][8])
    int nav2_V_L = 3;
    int nav2_V_C = 8;

    // Navio 3: Diagonal Descendente (L++, C++)
    // (Ocupará [4][1], [5][2], [6][3])
    int nav3_D1_L = 4;
    int nav3_D1_C = 1;
    
    // Navio 4: Diagonal Ascendente (L--, C++)
    // (Ocupará [8][4], [7][5], [6][6])
    int nav4_D2_L = 8;
    int nav4_D2_C = 4;

    
    // --- 3. Posicionamento Navio 1 (Horizontal) ---
    // Valida Limites
    if ((nav1_H_C + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        // Posiciona
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[nav1_H_L][nav1_H_C + j] = NAVIO;
        }
    } else {
        printf("Erro Crítico: Navio 1 (Horizontal) fora dos limites!\n");
        return 1;
    }

    // --- 4. Posicionamento Navio 2 (Vertical) ---
    // Valida Limites
    if ((nav2_V_L + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        
        // Valida Sobreposição (Verifica se colide com o Navio 1)
        sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[nav2_V_L + i][nav2_V_C] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        
        // Posiciona (se não houver sobreposição)
        if (sobreposicao == 0) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[nav2_V_L + i][nav2_V_C] = NAVIO;
            }
        } else {
            printf("Erro Crítico: Navio 2 (Vertical) está sobrepondo!\n");
            return 1;
        }

    } else {
        printf("Erro Crítico: Navio 2 (Vertical) fora dos limites!\n");
        return 1;
    }

    // --- 5. Posicionamento Navio 3 (Diagonal Descendente L++, C++) ---
    
    // Valida Limites (Precisa checar Linha E Coluna)
    if ((nav3_D1_L + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO && 
        (nav3_D1_C + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        
        // Valida Sobreposição (Verifica células na diagonal)
        sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica [L+i][C+i]
            if (tabuleiro[nav3_D1_L + i][nav3_D1_C + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona (se não houver sobreposição)
        if (sobreposicao == 0) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[nav3_D1_L + i][nav3_D1_C + i] = NAVIO;
            }
        } else {
            printf("Erro Crítico: Navio 3 (Diagonal Desc.) está sobrepondo!\n");
            return 1;
        }

    } else {
        printf("Erro Crítico: Navio 3 (Diagonal Desc.) fora dos limites!\n");
        return 1;
    }

    // --- 6. Posicionamento Navio 4 (Diagonal Ascendente L--, C++) ---
    
    // Valida Limites (Linha DECRESCE, Coluna AUMENTA)
    // A linha não pode ser menor que 0
    // A coluna não pode ser maior que o limite
    if ((nav4_D2_L - (TAMANHO_NAVIO - 1)) >= 0 && 
        (nav4_D2_C + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {

        // Valida Sobreposição
        sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica [L-i][C+i]
            if (tabuleiro[nav4_D2_L - i][nav4_D2_C + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        
        // Posiciona (se não houver sobreposição)
        if (sobreposicao == 0) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[nav4_D2_L - i][nav4_D2_C + i] = NAVIO;
            }
        } else {
            printf("Erro Crítico: Navio 4 (Diagonal Asc.) está sobrepondo!\n");
            return 1;
        }
        
    } else {
        printf("Erro Crítico: Navio 4 (Diagonal Asc.) fora dos limites!\n");
        return 1;
    }


    // --- 7. Exibição do Tabuleiro ---
    printf("\n### Batalha Naval - Tabuleiro (Nível Intermediário) ###\n\n");
    
    // Cabeçalho das Colunas
    printf("   "); 
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf(" %d ", col);
    }
    printf("\n");

    // Imprime Linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Cabeçalho da Linha
        printf(" %d ", i);
        
        // Imprime Células (Água ou Navio)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha
    }
    printf("\n--------------------------------------------------\n");

    return 0; // Sucesso
}