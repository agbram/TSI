#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Definição da struct Produto
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
    struct Produto *proximo;
} Produto;

// Protótipos das funções
void exibirMenu();
int adicionarProduto(Produto **estoque, int totalProdutos);
void exibirProdutos(Produto estoque[], int totalProdutos);
void adicionarEstoque(Produto estoque[], int totalProdutos);
void removerEstoque(Produto estoque[], int totalProdutos);
void calcularValorTotalEstoque(Produto estoque[], int totalProdutos);

int main() {
    // Declaração do vetor de structs
    Produto estoque[100]; // Capacidade máxima de 100 produtos
    int totalProdutos = 0;
    int opcao;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &totalProdutos);
                break;
            case 2:
                exibirProdutos(estoque, totalProdutos);
                break;
            case 3:
                adicionarEstoque(estoque, totalProdutos);
                break;
            case 4:
                removerEstoque(estoque, totalProdutos);
                break;
            case 5:
                calcularValorTotalEstoque(estoque, totalProdutos);
                break;
            case 6:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        printf("\n");
    } while (opcao != 6);

    return 0;
}

void exibirMenu() {
    printf("--- Menu de Gerenciamento de Produtos ---\n");
    printf("1. Adicionar novo produto\n");
    printf("2. Exibir lista de produtos\n");
    printf("3. Adicionar itens ao estoque\n");
    printf("4. Remover itens do estoque\n");
    printf("5. Calcular valor total do estoque\n");
    printf("6. Sair\n");
}

int adicionarProduto(Produto estoque[], int *totalProdutos) {
    if (*totalProdutos >= 100) {
        printf("Erro: Limite de produtos atingido!\n");
        return 0;
    }
    printf("--- Cadastro de Produto ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", estoque[*totalProdutos].nome); // Ler a linha inteira, incluindo espaços
    printf("Quantidade em estoque: ");
    scanf("%d", &estoque[*totalProdutos].quantidade);
    printf("Preco unitario: ");
    scanf("%f", &estoque[*totalProdutos].preco);

    (*totalProdutos)++;
    printf("Produto adicionado com sucesso!\n");
    return 1;
}

void exibirProdutos(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("--- Lista de Produtos ---\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", estoque[i].nome);
        printf("  Quantidade: %d\n", estoque[i].quantidade);
        printf("  Preco: R$ %.2f\n", estoque[i].preco);
        printf("-------------------------\n");
    }
}

void adicionarEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado para adicionar estoque.\n");
        return;
    }
    int indice, valor;
    printf("Informe o numero do produto para adicionar estoque (1 a %d): ", totalProdutos);
    scanf("%d", &indice);
    indice--; // Ajusta para o índice do array (começa em 0)

    if (indice < 0 || indice >= totalProdutos) {
        printf("Numero de produto invalido.\n");
        return;
    }

    printf("Produto selecionado: %s\n", estoque[indice].nome);
    printf("Quantidade a adicionar: ");
    scanf("%d", &valor);

    if (valor > 0) {
        estoque[indice].quantidade += valor;
        printf("Estoque atualizado com sucesso! Nova quantidade: %d\n", estoque[indice].quantidade);
    } else {
        printf("Valor a adicionar deve ser maior que zero.\n");
    }
}

void removerEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado para remover estoque.\n");
        return;
    }
    int indice, valor;
    printf("Informe o numero do produto para remover estoque (1 a %d): ", totalProdutos);
    scanf("%d", &indice);
    indice--; // Ajusta para o índice do array

    if (indice < 0 || indice >= totalProdutos) {
        printf("Numero de produto invalido.\n");
        return;
    }

    printf("Produto selecionado: %s\n", estoque[indice].nome);
    printf("Quantidade a remover: ");
    scanf("%d", &valor);

    if (valor > 0) {
        if (estoque[indice].quantidade >= valor) {
            estoque[indice].quantidade -= valor;
            printf("Estoque atualizado com sucesso! Nova quantidade: %d\n", estoque[indice].quantidade);
        } else {
            printf("Erro: Nao ha estoque suficiente para remover.\n");
        }
    } else {
        printf("Valor a remover deve ser maior que zero.\n");
    }
}

void calcularValorTotalEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("--- Valor Total do Estoque ---\n");
    for (int i = 0; i < totalProdutos; i++) {
        float valorTotal = estoque[i].quantidade * estoque[i].preco;
        printf("Produto: %s | Valor Total: R$ %.2f\n", estoque[i].nome, valorTotal);
    }
}