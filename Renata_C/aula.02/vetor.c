#include <stdio.h>

// Define um tamanho máximo para o vetor.
// Este é o limite da nossa "lista" baseada em vetor.
#define MAX_SIZE 10

// Protótipos das funções
void insere(int vetor[], int *tamanhoAtual, int valor);
void imprimeVetor(int vetor[], int tamanhoAtual);

int main() {
    // 1. Declaração do vetor e inicialização do tamanho atual
    //    A memória é alocada de forma estática, na stack.
    int numeros[MAX_SIZE];
    int tamanho = 0; // Controla quantos elementos foram realmente adicionados

    printf("Criando uma 'lista' com vetor...\n");

    // 2. Inserindo elementos no vetor
    //    A função insere() adiciona o valor na próxima posição disponível.
    insere(numeros, &tamanho, 10);
    insere(numeros, &tamanho, 25);
    insere(numeros, &tamanho, 7);
    insere(numeros, &tamanho, 42);

    printf("Vetor criado com sucesso!\n\n");

    // 3. Imprimindo os elementos do vetor
    imprimeVetor(numeros, tamanho);

    printf("\n");

    // Teste: Tentando adicionar mais elementos do que a capacidade
    insere(numeros, &tamanho, 55);
    insere(numeros, &tamanho, 66);
    insere(numeros, &tamanho, 77);
    insere(numeros, &tamanho, 88);
    insere(numeros, &tamanho, 99);
    insere(numeros, &tamanho, 101); // Este não será inserido, pois o vetor está cheio.
    insere(numeros, &tamanho, 112); // Este também não será inserido.

    imprimeVetor(numeros, tamanho);
    
    return 0;
}

// Função para inserir um novo valor no final do vetor
void insere(int vetor[], int *tamanhoAtual, int valor) {
    // Verifica se há espaço disponível antes de inserir
    if (*tamanhoAtual < MAX_SIZE) {
        // Acesso direto pela posição do array
        vetor[*tamanhoAtual] = valor; 
        (*tamanhoAtual)++; // Incrementa o contador de elementos
    } else {
        printf("Erro: O vetor esta cheio. Nao foi possivel inserir o valor %d.\n", valor);
    }
}

// Função para percorrer e imprimir o vetor
void imprimeVetor(int vetor[], int tamanhoAtual) {
    if (tamanhoAtual == 0) {
        printf("O vetor esta vazio.\n");
        return;
    }

    printf("Conteúdo do vetor: ");
    for (int i = 0; i < tamanhoAtual; i++) {
        // Acesso direto e rápido a cada elemento pelo seu índice
        printf("%d ", vetor[i]); 
    }
    printf("\n");
}

