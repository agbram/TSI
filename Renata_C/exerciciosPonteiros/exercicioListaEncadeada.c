#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int valor;            // dado armazenado
    struct Node *prox;      // ponteiro para o próximo nó
};

// Função para inserir no início da lista
struct Node* inserirInicio(struct Node *inicio, int numero) {
    // Aloca memória para o novo nó
    struct Node *novo = (struct Node*) malloc(sizeof(struct Node));

    if (novo == NULL) { // sempre bom checar se deu certo
        printf("Erro ao alocar memoria!\n");
        return inicio;
    }

    // Coloca o valor dentro do nó
    novo->valor = numero;

    // Faz o novo nó apontar para o antigo início
    novo->prox = inicio;

    // Atualiza o início para ser o novo nó
    return novo;
}

// Função para imprimir a lista
void imprimirLista(struct Node *inicio) {
    struct Node *temp = inicio; // ponteiro auxiliar
    printf("Lista encadeada: ");
    while (temp != NULL) { // percorre até o fim
        printf("%d -> ", temp->valor);
        temp = temp->prox; // anda para o próximo nó
    }
    printf("NULL\n"); // fim da lista
}

int main() {
    struct Node *inicio = NULL; // lista começa vazia
    int numero;

    // Lê números até o usuário digitar 0
    do {
        printf("Digite um numero (0 para parar): ");
        scanf("%d", &numero);

        if (numero != 0) {
            // insere no início e atualiza o ponteiro de início
            inicio = inserirInicio(inicio, numero);
        }

    } while (numero != 0);

    // Mostra a lista final
    imprimirLista(inicio);

    // Liberar memória (boa prática)
    struct Node *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }

    return 0;
}
