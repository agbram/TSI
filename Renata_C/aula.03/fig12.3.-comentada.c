/* Fig. 12.3: fig12_03.c
   Operando e mantendo uma lista */
#include <stdio.h>
#include <stdlib.h> /* para malloc e free */

/* estrutura autorreferenciada */
struct listNode
{
    char data;                /* cada listNode contem um caractere */
    struct listNode *nextPtr; /* ponteiro para proximo no */
}; /* fim da estrutura listNode */

typedef struct listNode ListNode; /* sinonimo de struct listNode */
typedef ListNode *ListNodePtr;    /* sinonimo de ListNode */

/* prototipos */
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{
    ListNodePtr startPtr = NULL; /* inicialmente nao existem nos */
    int choice;                  /* escolha do usuario */
    char item;                   /* char inserido pelo usuario */

    system("clear");

    instructions(); /* exibe o menu */
    printf("? ");
    scanf("%d", &choice);

    /* loop enquanto usuario nao escolhe 3 */
    while (choice != 3)
    {

        switch (choice)
        {
        case 1:
            printf("\n--- Operacao: Inserir ---\n");
            printf("Digite um caractere para inserir: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); /* insere item na lista */
            printList(startPtr);
            break;
        case 2: /* exclui um elemento */
            printf("\n--- Operacao: Excluir ---\n");
            /* se lista nao esta vazia */
            if (!isEmpty(startPtr))
            {
                printf("Digite o caractere a ser excluido: ");
                scanf("\n%c", &item);

                /* se caractere for encontrado, e removido */
                if (delete(&startPtr, item))
                { /* remove item */
                    printf("  [INFO DELETE] Caractere '%c' excluido com sucesso.\n", item);
                    printList(startPtr);
                } /* fim do if */
                else
                {
                    printf("  [INFO DELETE] Caractere '%c' nao encontrado na lista.\n\n", item);
                } /* fim do else */
            } /* fim do if */
            else
            {
                printf("  [INFO DELETE] Lista esta vazia. Nada para excluir.\n\n");
            } /* fim do else */

            break;
        default:
            printf("Escolha invalida. Tente novamente.\n\n");
            instructions();
            break;
        } /* fim do switch */

        printf("? ");
        scanf("%d", &choice);
    } /* fim do while */

    printf("Fim da execucao.\n");
    return 0; /* indica conclusao bem-sucedida */
} /* fim do main */

/* exibe instrucoes do programa ao usuario */
void instructions(void)
{
    printf("\n--- Menu ---\n");
    printf("Digite sua escolha:\n");
    printf("   1 para inserir um elemento na lista.\n");
    printf("   2 para excluir um elemento da lista.\n");
    printf("   3 para terminar o programa.\n");
    printf("------------\n");
} /* fim das instrucoes de funcao */

/* Insere novo valor na lista, na ordem classificada */
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr;      /* ponteiro para novo no */
    ListNodePtr previousPtr; /* ponteiro para no anterior na lista */
    ListNodePtr currentPtr;  /* ponteiro para no atual na lista */

    printf("  [INFO INSERT] Tentando inserir o caractere: '%c'\n", value);

    printf("  [INFO INSERT] 1. Alocando memoria para o novo no (newPtr).\n");
    newPtr = malloc(sizeof(ListNode)); /* cria no */

    if (newPtr != NULL)
    { /* espaco esta disponivel */
        printf("  [INFO INSERT]    Memoria alocada com sucesso para newPtr (Endereco: %p).\n", (void *)newPtr);
        newPtr->data = value; /* coloca valor no no */
        printf("  [INFO INSERT]    Atribuindo o valor '%c' ao campo 'data' de newPtr.\n", newPtr->data);
        newPtr->nextPtr = NULL; /* no nao se une a outro no */
        printf("  [INFO INSERT]    Definindo 'nextPtr' de newPtr como NULL (Endereco: %p).\n", (void *)newPtr->nextPtr);

        previousPtr = NULL;
        currentPtr = *sPtr;
        printf("  [INFO INSERT] 2. Inicializando ponteiros de travessia.\n");
        printf("  [INFO INSERT]    previousPtr = NULL (Endereco: %p).\n", (void *)previousPtr);
        printf("  [INFO INSERT]    currentPtr = *sPtr (HEAD da lista) (Endereco: %p).\n", (void *)currentPtr);

        printf("  [INFO INSERT] 3. Percorrendo a lista para encontrar o local de insercao (mantendo ordem crescente).\n");
        /* loop para achar o local correto na lista */
        while (currentPtr != NULL && value > currentPtr->data)
        {
            printf("  [INFO INSERT]    currentPtr (data: '%c') e menor que '%c'. Movendo para o proximo no.\n", currentPtr->data, value);
            previousPtr = currentPtr;         /* caminha para ...*/
            currentPtr = currentPtr->nextPtr; /* ... proximo no */
            printf("  [INFO INSERT]    previousPtr agora aponta para %p (data: '%c').\n", (void *)previousPtr, previousPtr->data);
            printf("  [INFO INSERT]    currentPtr agora aponta para %p.\n", (void *)currentPtr);
        } /* fim do while */
        printf("  [INFO INSERT]    Loop de travessia finalizado.\n");

        /* insere novo no no inicio da lista */
        if (previousPtr == NULL)
        {
            printf("  [INFO INSERT] 4. previousPtr e NULL. Inserindo no INICIO da lista.\n");
            newPtr->nextPtr = *sPtr; // O novo no aponta para o antigo inicio
            printf("  [INFO INSERT]    newPtr->nextPtr (%p) agora aponta para o antigo *sPtr (%p).\n", (void *)newPtr->nextPtr, (void *)*sPtr);
            *sPtr = newPtr; // O ponteiro de inicio da lista (HEAD) agora aponta para o novo no
            printf("  [INFO INSERT]    *sPtr (HEAD) agora aponta para newPtr (%p).\n", (void *)*sPtr);
        } /* fim do if */
        else
        { /* insere novo no entre previousPtr e currentPtr */
            printf("  [INFO INSERT] 4. previousPtr NAO e NULL. Inserindo NO MEIO/FINAL da lista.\n");
            previousPtr->nextPtr = newPtr; // O no anterior aponta para o novo no
            printf("  [INFO INSERT]    previousPtr->nextPtr (%p) agora aponta para newPtr (%p).\n", (void *)previousPtr->nextPtr, (void *)newPtr);
            newPtr->nextPtr = currentPtr; // O novo no aponta para o no que era o proximo do anterior
            printf("  [INFO INSERT]    newPtr->nextPtr (%p) agora aponta para currentPtr (%p).\n", (void *)newPtr->nextPtr, (void *)currentPtr);
        } /* fim do else */
        printf("  [INFO INSERT] Caractere '%c' inserido com sucesso na lista.\n", value);
    } /* fim do if */
    else
    {
        printf("  [INFO INSERT] ERRO: %c nao inserido. Sem memoria disponivel.\n", value);
    } /* fim do else */
    printf("---------------------------\n");
} /* fim da funcao insert */

/* Exclui um elemento da lista */
char delete(ListNodePtr *sPtr, char value)
{
    ListNodePtr previousPtr; /* ponteiro para no anterior na lista */
    ListNodePtr currentPtr;  /* ponteiro para no atual na lista */
    ListNodePtr tempPtr;     /* ponteiro de no temporario */

    printf("  [INFO DELETE] Tentando excluir o caractere: '%c'\n", value);

    // Adicao da verificacao de lista vazia para evitar segmentation fault
    if (*sPtr == NULL)
    {
        printf("  [INFO DELETE] ERRO: Lista vazia. Nao ha nada para excluir.\n");
        return '\0'; // Nao ha nada para excluir
    }

    printf("  [INFO DELETE] 1. Verificando se o elemento a ser excluido e o primeiro no (HEAD).\n");
    /* exclui primeiro no */
    if (value == (*sPtr)->data)
    {
        printf("  [INFO DELETE]    Caractere '%c' encontrado no inicio da lista.\n", value);
        tempPtr = *sPtr; /* aponta para o no que esta sendo removido */
        printf("  [INFO DELETE]    tempPtr (%p) aponta para o no a ser removido (o antigo *sPtr).\n", (void *)tempPtr);
        *sPtr = (*sPtr)->nextPtr; /* o HEAD da lista agora aponta para o proximo no */
        printf("  [INFO DELETE]    *sPtr (HEAD) agora aponta para o proximo no (%p).\n", (void *)*sPtr);
        free(tempPtr); /* libera o no retirado */
        printf("  [INFO DELETE]    Memoria do no %p (dado: '%c') liberada.\n", (void *)tempPtr, value);
        return value;
    } /* fim do if */
    else
    {
        printf("  [INFO DELETE]    Caractere '%c' NAO e o primeiro no. Percorrendo a lista.\n", value);
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;
        printf("  [INFO DELETE]    previousPtr inicializado para *sPtr (%p).\n", (void *)previousPtr);
        printf("  [INFO DELETE]    currentPtr inicializado para (*sPtr)->nextPtr (%p).\n", (void *)currentPtr);

        printf("  [INFO DELETE] 2. Percorrendo a lista para encontrar o no a ser excluido.\n");
        /* loop para achar local correto na lista */
        while (currentPtr != NULL && currentPtr->data != value)
        {
            printf("  [INFO DELETE]    currentPtr (data: '%c') nao e '%c'. Movendo para o proximo no.\n", currentPtr->data, value);
            previousPtr = currentPtr;         /* caminha ate ... */
            currentPtr = currentPtr->nextPtr; /* ... proximo no */
            printf("  [INFO DELETE]    previousPtr agora aponta para %p (data: '%c').\n", (void *)previousPtr, previousPtr->data);
            printf("  [INFO DELETE]    currentPtr agora aponta para %p.\n", (void *)currentPtr);
        } /* fim do while */
        printf("  [INFO DELETE]    Loop de travessia finalizado.\n");

        /* exclui no em currentPtr */
        if (currentPtr != NULL)
        {
            printf("  [INFO DELETE] 3. Caractere '%c' encontrado (no endereco %p). Excluindo do meio/fim da lista.\n", value, (void *)currentPtr);
            tempPtr = currentPtr; // Guarda o no a ser excluido
            printf("  [INFO DELETE]    tempPtr (%p) aponta para o no a ser removido.\n", (void *)tempPtr);
            previousPtr->nextPtr = currentPtr->nextPtr; // O no anterior aponta para o que vinha DEPOIS do no excluido
            printf("  [INFO DELETE]    previousPtr->nextPtr (%p) agora aponta para currentPtr->nextPtr (%p).\n", (void *)previousPtr->nextPtr, (void *)currentPtr->nextPtr);
            free(tempPtr); // Libera a memoria do no
            printf("  [INFO DELETE]    Memoria do no %p (dado: '%c') liberada.\n", (void *)tempPtr, value);
            return value;
        } /* fim do if */
    } /* fim do else */

    printf("  [INFO DELETE] Caractere '%c' nao encontrado na lista apos travessia.\n", value);
    printf("---------------------------\n");
    return '\0'; // Caractere nao encontrado
} /* fim da funcao delete */

/* Retorna 1 se a lista estiver vazia, 0 se estiver cheia */
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
} /* fim da funcao isEmpty */

/* Imprime a lista */
void printList(ListNodePtr currentPtr)
{
    printf("--- Estado Atual da Lista ---\n");
    /* se lista estiver vazia */
    if (currentPtr == NULL)
    {
        printf("Lista esta vazia.\n\n");
    } /* fim do if */
    else
    {
        printf("A lista e: HEAD --> ");

        /* enquanto nao chega ao final da lista */
        while (currentPtr != NULL)
        {
            printf("'%c' (%p) --> ", currentPtr->data, (void *)currentPtr);
            currentPtr = currentPtr->nextPtr;
        } /* fim do while */

        printf("NULL\n\n");
    } /* fim do else */
    printf("---------------------------\n");
} /* fim da funcao printList */
