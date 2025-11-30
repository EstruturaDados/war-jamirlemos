// ============================================================================
//               DESAFIO WAR ESTRUTURADO – NÍVEL NOVATO
// ============================================================================
// Objetivo deste exercício:
// - Criar uma struct para armazenar dados de territórios.
// - Utilizar um vetor estático para guardar 5 territórios.
// - Ler nome, cor do exército e número de tropas para cada território.
// - Exibir o estado atual do mapa.
// - Praticar entrada e saída (scanf, fgets), structs e vetores.
// ============================================================================

#include <stdio.h>      // Biblioteca padrão para entrada e saída (printf, scanf, fgets)
#include <string.h>     // Biblioteca usada para manipulação de strings (strcspn)
#include <stdlib.h>     // Biblioteca padrão (não é usada aqui, mas costuma ser incluída para malloc/free)
#include <locale.h>     // Biblioteca para configurar o idioma e acentuação no terminal

// Número fixo de territórios do mapa.
// O uso de uma constante facilita manutenção e evita "números mágicos" no código.
#define TOTAL_TERRITORIOS 5

// ============================================================================
// ESTRUTURA DE DADOS: struct Territorio
// ============================================================================
// A struct agrupa os dados que compõem um território no jogo WAR.
// - nome: nome do território.
// - cor: cor do exército que domina o território.
// - tropas: quantidade de tropas estacionadas nele.
// ============================================================================

typedef struct {
    char nome[50];  // Nome do território (string)
    char cor[20];   // Cor do exército (string)
    int tropas;     // Número de tropas (inteiro)
} Territorio;

// ============================================================================
// FUNÇÃO PRINCIPAL
// ============================================================================
// A função main orquestra o fluxo do programa:
// 1. Cria o vetor de territórios.
// 2. Lê os dados de cada um via teclado.
// 3. Exibe o estado final do mapa.
// ============================================================================

int main() {

    setlocale(LC_ALL,"Portuguese_Brazil");
    // Vetor estático contendo 5 estruturas Territorio.
    // Cada índice do vetor representa um território distinto.
    Territorio mapa[TOTAL_TERRITORIOS];
    int i; // Variável de controle para loops

    printf("=== DESAFIO WAR ESTRUTURADO - NIVEL NOVATO ===\n\n");

    // =========================================================================
    // 1. LEITURA DOS DADOS DE CADA TERRITÓRIO
    // =========================================================================
    // Para cada território, pedimos ao usuário:
    // - Nome (com fgets)
    // - Cor do exército (fgets)
    // - Número de tropas (scanf)
    // =========================================================================

    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        // -------------------------
        // Leitura do nome
        // -------------------------
        printf("Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);

        // fgets mantém o '\n' no final da string; esta linha remove ele.
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        // -------------------------
        // Leitura da cor do exército
        // -------------------------
        printf("Cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';  // Remove o newline

        // -------------------------
        // Leitura do número de tropas
        // -------------------------
        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);

        // Após um scanf, fica um '\n' pendente no buffer.
        // Usamos getchar() para consumir esse caractere e evitar problemas
        // com o próximo fgets.
        getchar();
    }

    // =========================================================================
    // 2. EXIBIÇÃO FINAL DO MAPA
    // =========================================================================
    
    printf("\n\n===== ESTADO ATUAL DO MAPA =====\n");

    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }

    printf("\n=================================\n");

    // Finaliza o programa com sucesso.
    return 0;
}