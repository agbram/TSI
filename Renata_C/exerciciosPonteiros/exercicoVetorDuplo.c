#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd, *vetorA, *vetorB, *vetorC;

    printf("Quantos elementos deseja em cada vetor? ");
    scanf("%d", &qtd);

    vetorA = (int *) malloc(qtd * sizeof(int));
    vetorB = (int *) malloc(qtd * sizeof(int));
    vetorC = (int *) malloc(qtd * sizeof(int));

    if (vetorA == NULL || vetorB == NULL || vetorC == NULL) {
        printf("Erro na alocacao da memoria!\n");
        return 1;
    }

    printf("\nDigite os elementos do vetor A:\n");
    for (int i = 0; i < qtd; i++) {
        printf("A[%d]: ", i + 1);
        scanf("%d", (vetorA + i));
    }

    printf("\nDigite os elementos do vetor B:\n");
    for (int i = 0; i < qtd; i++) {
        printf("B[%d]: ", i + 1);
        scanf("%d", (vetorB + i));
    }

    // soma
    for (int i = 0; i < qtd; i++) {
        *(vetorC + i) = *(vetorA + i) + *(vetorB + i);
    }

    printf("\nResultado da soma (vetor C):\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", *(vetorC + i));
    }

    free(vetorA);
    free(vetorB);
    free(vetorC);

    return 0;
}
