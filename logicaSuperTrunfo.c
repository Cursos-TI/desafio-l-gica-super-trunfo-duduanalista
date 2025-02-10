#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 32 // 8 estados * 4 cidades por estado

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char codigo[4];    // Código da carta (Ex: A01, B02)
    char nome[50];     // Nome da cidade
    int populacao;     // População da cidade
    float area;        // Área total em km²
    float pib;         // PIB da cidade
    int pontosTuristicos; // Número de pontos turísticos
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta cartas[], int *quantidade) {
    if (*quantidade >= MAX_CARTAS) {
        printf("Limite de cartas atingido!\n");
        return;
    }

    Carta nova;
    printf("\nDigite o código da cidade (Ex: A01, B02): ");
    scanf("%s", nova.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nova.nome);
    printf("Digite a população da cidade: ");
    scanf("%d", &nova.populacao);
    printf("Digite a área da cidade em km²: ");
    scanf("%f", &nova.area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &nova.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova.pontosTuristicos);

    cartas[*quantidade] = nova;
    (*quantidade)++;
    printf("Carta cadastrada com sucesso!\n");
}

// Função para exibir todas as cartas cadastradas
void exibirCartas(Carta cartas[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhuma carta cadastrada ainda!\n");
        return;
    }

    printf("\n===== CARTAS CADASTRADAS =====\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("Nome: %s\n", cartas[i].nome);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("------------------------------\n");
    }
}

int main() {
    Carta cartas[MAX_CARTAS]; // Armazena todas as cartas cadastradas
    int quantidade = 0; // Quantidade atual de cartas

    int opcao;
    do {
        printf("\n===== SUPER TRUNFO - PAISES =====\n");
        printf("1 - Cadastrar nova carta\n");
        printf("2 - Exibir cartas cadastradas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(cartas, &quantidade);
                break;
            case 2:
                exibirCartas(cartas, quantidade);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
