// Inclui a biblioteca padrão de Entrada/Saída (para usar printf)
#include <stdio.h>

// --- Constantes do Jogo ---
// Define o tamanho fixo do tabuleiro (10x10)
#define TAMANHO_TABULEIRO 10
// Define o tamanho fixo dos navios (3 posições)
#define TAMANHO_NAVIO 3

// Valor para representar a Água
#define AGUA 0
// Valor para representar um Navio
#define NAVIO 3


int main() {
    
    // --- 1. Representação do Tabuleiro ---
    // Declara a matriz (array bidimensional) 10x10 para o tabuleiro.
    // O tipo 'int' permite armazenar os valores 0 (água) e 3 (navio).
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // --- 2. Inicialização do Tabuleiro ---
    // Precisamos "limpar" o tabuleiro, preenchendo tudo com ÁGUA (0).
    // Loop 'i' percorre as LINHAS (de 0 a 9)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop 'j' percorre as COLUNAS (de 0 a 9)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Define a célula na [linha][coluna] com o valor de ÁGUA
            tabuleiro[i][j] = AGUA;
        }
    }

    /*
     * --- 3. Posicionamento dos Navios (Hardcoded) ---
     * Conforme o requisito, as coordenadas são definidas aqui no código.
     * Você pode alterar esses valores para mudar onde os navios aparecem.
     * * Nota sobre coordenadas: Matrizes em C começam em 0.
     * Linha 0 é a primeira linha. Coluna 0 é a primeira coluna.
     */
    
    // Definições do Navio 1 (Horizontal)
    int navio1_linha = 2;          // Linha fixa (linha 2)
    int navio1_coluna_inicio = 3;  // Coluna inicial (coluna 3)
    // Ocupará: [2][3], [2][4], [2][5]

    // Definições do Navio 2 (Vertical)
    int navio2_linha_inicio = 5;   // Linha inicial (linha 5)
    int navio2_coluna = 7;         // Coluna fixa (coluna 7)
    // Ocupará: [5][7], [6][7], [7][7]
    

    // --- 4. Validação e Colocação do Navio 1 (Horizontal) ---
    
    // Requisito: Validar se o navio cabe nos limites do tabuleiro.
    // A coluna final (inicio + tamanho) deve ser MENOR OU IGUAL ao tamanho do tabuleiro.
    if ((navio1_coluna_inicio + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        
        // Se couber, "desenha" o navio na matriz.
        // O loop 'j' percorre o *tamanho do navio* (0, 1, 2)
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            // A linha é fixa, a coluna é incrementada (coluna_inicio + j)
            tabuleiro[navio1_linha][navio1_coluna_inicio + j] = NAVIO;
        }
    } else {
        // Se não couber, avisa o usuário e encerra (é um erro de configuração)
        printf("Erro Crítico: Navio 1 (Horizontal) está fora dos limites!\n");
        return 1; // Encerra o programa com código de erro
    }

    // --- 5. Validação e Colocação do Navio 2 (Vertical) ---
    
    // Requisito: Validar Limites (Vertical)
    // A linha final (inicio + tamanho) deve ser MENOR OU IGUAL ao tamanho do tabuleiro.
    if ((navio2_linha_inicio + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        
        // Requisito: Validar Sobreposição (Simplificado)
        int sobreposicao = 0; // 0 = Não há sobreposição (Falso), 1 = Há (Verdadeiro)
        
        // Loop 'i' percorre o *tamanho do navio* (0, 1, 2)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se a posição (linha_inicio + i, coluna) JÁ está ocupada (é != AGUA)
            if (tabuleiro[navio2_linha_inicio + i][navio2_coluna] != AGUA) {
                sobreposicao = 1; // Marca que encontrou sobreposição
                break;            // Para o loop, não precisa verificar o resto
            }
        }

        // Se (if) não (not !) houver sobreposição (sobreposicao == 0)
        if (sobreposicao == 0) {
            
            // "Desenha" o navio na matriz
            // Loop 'i' percorre o *tamanho do navio*
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                // A coluna é fixa, a linha é incrementada (linha_inicio + i)
                tabuleiro[navio2_linha_inicio + i][navio2_coluna] = NAVIO;
            }
        } else {
            // Se houver sobreposição, avisa e encerra
            printf("Erro Crítico: Navio 2 (Vertical) está sobrepondo o Navio 1!\n");
            return 1; // Encerra o programa com código de erro
        }

    } else {
        // Se não couber (Vertical), avisa e encerra
        printf("Erro Crítico: Navio 2 (Vertical) está fora dos limites!\n");
        return 1; // Encerra o programa com código de erro
    }

    // --- 6. Exibição do Tabuleiro ---
    // Requisito: Exibir o tabuleiro no console de forma clara.
    
    printf("\n### Batalha Naval - Tabuleiro (Nível Novato) ###\n\n");
    
    // Imprime cabeçalho das colunas (Bônus, para facilitar leitura)
    printf("   "); // Espaço para as linhas
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf(" %d ", col);
    }
    printf("\n");

    // Loop 'i' para percorrer as LINHAS
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        
        // Imprime cabeçalho da linha (Bônus)
        printf(" %d ", i);
        
        // Loop 'j' para percorrer as COLUNAS
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            // Imprime o valor da célula (0 para água, 3 para navio)
            // O " %d " (com espaços) ajuda na formatação e alinhamento
            printf(" %d ", tabuleiro[i][j]);
        }
        // Ao final de cada linha (loop 'j' interno), pula para a próxima linha
        printf("\n");
    }
    printf("\n--------------------------------------------------\n");

    // Se o programa chegou até aqui, tudo correu bem.
    return 0; // Indica que o programa terminou com sucesso
}