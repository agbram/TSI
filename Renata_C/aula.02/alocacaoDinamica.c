#include <stdio.h>
#include <stdlib.h>

// 1. Definição da Estrutura Autorreferenciada (struct node)
//    Cada 'node' contém um valor (numero) e um ponteiro para o próximo 'node'.
struct node {
    int numero;
    struct node *nextPtr;
};

// Define um novo tipo de dados para facilitar o uso
typedef struct node Node;

// Protótipos das funções
void insere(Node **headPtr, int value);
void imprimeLista(Node *currentPtr);
void liberaLista(Node **headPtr);

int main() {
    // Inicializa o ponteiro principal da lista como NULL
    // Isso indica que a lista está vazia no começo.
    Node *head = NULL;

    printf("Criando uma lista encadeada...\n");

    // 2. Usando Alocação Dinâmica para adicionar nós
    //    A função insere() usa malloc() para criar novos nós dinamicamente.
    insere(&head, 10);
    insere(&head, 25);
    insere(&head, 7);
    insere(&head, 42);

    printf("Lista criada com sucesso!\n\n");

    // 3. Imprimindo os elementos da lista
    imprimeLista(head);

    // 4. Liberando a memória alocada
    //    É crucial liberar a memória com free() para evitar memory leaks.
    liberaLista(&head);

    printf("\nMemória da lista liberada com sucesso.\n");

    return 0;
}

// Função para inserir um novo nó no final da lista
void insere(Node **headPtr, int value) {
    // Aloca memória para o novo nó
    Node *novoNode = malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    // Atribui o valor ao novo nó e define seu ponteiro como NULL
    novoNode->numero = value;
    novoNode->nextPtr = NULL;

    // Se a lista estiver vazia, o novo nó se torna a 'cabeça' da lista
    if (*headPtr == NULL) {
        *headPtr = novoNode;
    } else {
        // Senão, percorre a lista até o último nó
        Node *currentPtr = *headPtr;
        while (currentPtr->nextPtr != NULL) {
            currentPtr = currentPtr->nextPtr;
        }
        // E anexa o novo nó ao final
        currentPtr->nextPtr = novoNode;
    }
}

// Função para percorrer e imprimir a lista
void imprimeLista(Node *currentPtr) {
    if (currentPtr == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Conteúdo da lista: ");
    while (currentPtr != NULL) {
        printf("%d --> ", currentPtr->numero);
        currentPtr = currentPtr->nextPtr; // Move para o próximo nó
    }
    printf("NULL\n");
}

// Função para liberar a memória de todos os nós da lista
void liberaLista(Node **headPtr) {
    Node *currentPtr = *headPtr;
    Node *tempPtr;

    while (currentPtr != NULL) {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr; // Move para o próximo antes de liberar
        free(tempPtr);                     // Libera a memória do nó atual
    }
    *headPtr = NULL; // Define a cabeça da lista como NULL após a liberação
}