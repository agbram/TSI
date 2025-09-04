#include <stdio.h>
#include <stdlib.h>


void aloca();

int main(){

    aloca();

    return 0;
}

void aloca(){
    int qtd;

    int *ptr;

    printf("Quantos números deseja armazenar: ");
    scanf("%d", &qtd);

    ptr = (int *) malloc(qtd * sizeof(int));
    
    if(ptr == NULL){
        printf("Erro na alocacao da memória");
        return;
    }

    for(int i = 0; i < qtd; i++){
        printf("Digite o numero %d: ",i);
        scanf("%d", (ptr + i));
    }

    printf("\nVoce digitou: ");

    for(int i = 0; i < qtd; i++){
        printf("%d ", *(ptr + i));
    }

    free(ptr);

}
