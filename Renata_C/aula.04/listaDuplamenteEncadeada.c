#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// --- Typedef da Estrutura ---
// Define 'LISTA' como um novo tipo para a estrutura 'no'
typedef struct no {
    int num;
    struct no *prox;
    struct no *ant;
} LISTA;


// --- Protótipos das Funções ---
void exibir_menu();
void inserir_inicio(LISTA **inicio, LISTA **fim);
void inserir_fim(LISTA **inicio, LISTA **fim);
void consultar_inicio_fim(LISTA *inicio);
void consultar_fim_inicio(LISTA *fim);
void remover_elemento(LISTA **inicio, LISTA **fim);
void esvaziar_lista(LISTA **inicio, LISTA **fim);


// --- Função Principal ---
int main() {
    // Ponteiros para controlar a lista, agora do tipo LISTA
    LISTA *inicio = NULL;
    LISTA *fim = NULL;
    int op;

    do {
        exibir_menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                inserir_inicio(&inicio, &fim);
                break;
            case 2:
                inserir_fim(&inicio, &fim);
                break;
            case 3:
                consultar_inicio_fim(inicio);
                break;
            case 4:
                consultar_fim_inicio(fim);
                break;
            case 5:
                remover_elemento(&inicio, &fim);
                break;
            case 6:
                esvaziar_lista(&inicio, &fim);
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!!\n");
                break;
        }

        if (op > 0 && op < 7) {
            printf("\n\nPressione ENTER para continuar...");
            getchar(); // Limpa o buffer de entrada do scanf
            getchar(); // Aguarda o usuário pressionar Enter
        }

    } while (op != 7);

    // Libera qualquer memória restante antes de sair
    esvaziar_lista(&inicio, &fim);

    return 0;
}


// --- Implementação das Funções ---

/**
 * @brief Exibe o menu de opções para o usuário.
 */
void exibir_menu() {
    // system("cls"); // Descomente para limpar a tela no Windows
    printf("\nMENU DE OPCOES\n");
    printf("\n1 - Inserir no inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Consultar a lista do inicio ao fim");
    printf("\n4 - Consultar a lista do fim ao inicio");
    printf("\n5 - Remover da lista");
    printf("\n6 - Esvaziar a lista");
    printf("\n7 - Sair");
    printf("\nDigite sua opcao: ");
}

/**
 * @brief Insere um novo elemento no início da lista.
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param fim Ponteiro para o ponteiro do fim da lista.
 */
void inserir_inicio(LISTA **inicio, LISTA **fim) {
    printf("Digite o numero a ser inserido no inicio da lista: ");
    LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
    scanf("%d", &novo->num);

    if (*inicio == NULL) { // Lista vazia
        *inicio = novo;
        *fim = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    } else { // Lista contém elementos
        novo->prox = *inicio;
        (*inicio)->ant = novo;
        novo->ant = NULL;
        *inicio = novo;
    }
    printf("Numero inserido no inicio da lista!!");
}

/**
 * @brief Insere um novo elemento no final da lista.
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param fim Ponteiro para o ponteiro do fim da lista.
 */
void inserir_fim(LISTA **inicio, LISTA **fim) {
    printf("Digite o numero a ser inserido no fim da lista: ");
    LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
    scanf("%d", &novo->num);

    if (*inicio == NULL) { // Lista vazia
        *inicio = novo;
        *fim = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    } else { // Lista contém elementos
        (*fim)->prox = novo;
        novo->ant = *fim;
        novo->prox = NULL;
        *fim = novo;
    }
    printf("Numero inserido no fim da lista!!");
}

/**
 * @brief Percorre e exibe a lista do início ao fim.
 * @param inicio Ponteiro para o início da lista.
 */
void consultar_inicio_fim(LISTA *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia!!");
    } else {
        printf("\nConsultando a lista do inicio ao fim\n");
        LISTA *aux = inicio;
        while (aux != NULL) {
            printf("%d ", aux->num);
            aux = aux->prox;
        }
    }
}

/**
 * @brief Percorre e exibe a lista do fim ao início.
 * @param fim Ponteiro para o fim da lista.
 */
void consultar_fim_inicio(LISTA *fim) {
    if (fim == NULL) {
        printf("Lista vazia!!");
    } else {
        printf("\nConsultando a lista do fim ao inicio\n");
        LISTA *aux = fim;
        while (aux != NULL) {
            printf("%d ", aux->num);
            aux = aux->ant;
        }
    }
}

/**
 * @brief Remove todas as ocorrências de um número da lista.
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param fim Ponteiro para o ponteiro do fim da lista.
 */
void remover_elemento(LISTA **inicio, LISTA **fim) {
    if (*inicio == NULL) {
        printf("Lista vazia!!");
        return;
    }

    int numero, achou = 0;
    printf("\nDigite o elemento a ser removido: ");
    scanf("%d", &numero);

    LISTA *aux = *inicio;
    while (aux != NULL) {
        if (aux->num == numero) {
            achou++;
            if (aux == *inicio) { // Remove do início
                *inicio = aux->prox;
                if (*inicio != NULL) {
                    (*inicio)->ant = NULL;
                } else { // Lista ficou vazia
                    *fim = NULL;
                }
                free(aux);
                aux = *inicio;
            } else if (aux == *fim) { // Remove do fim
                *fim = aux->ant;
                (*fim)->prox = NULL;
                free(aux);
                aux = NULL; // Finaliza o loop
            } else { // Remove do meio
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                LISTA *proximo = aux->prox;
                free(aux);
                aux = proximo;
            }
        } else {
            aux = aux->prox;
        }
    }

    if (achou == 0) {
        printf("Numero nao encontrado");
    } else if (achou == 1) {
        printf("Numero removido 1 vez");
    } else {
        printf("Numero removido %d vezes", achou);
    }
}

/**
 * @brief Remove todos os elementos da lista, liberando a memória.
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param fim Ponteiro para o ponteiro do fim da lista.
 */
void esvaziar_lista(LISTA **inicio, LISTA **fim) {
    if (*inicio == NULL) {
        printf("Lista ja esta vazia!!");
        return;
    }
    
    LISTA *aux = *inicio;
    while (aux != NULL) {
        *inicio = aux->prox;
        free(aux);
        aux = *inicio;
    }
    *fim = NULL;
    printf("Lista esvaziada!!");
}