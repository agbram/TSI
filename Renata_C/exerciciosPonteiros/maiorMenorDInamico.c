#include <stdio.h>
#include <stdlib.h>

void maiorMenor();
int main(){

    maiorMenor();

    return 0;
}

void maiorMenor(){

    int qtd, *ptr, maior, menor;

    printf("Insira a quantidade de números desejada: ");
    scanf("%d", &qtd);

    ptr = (int *)malloc(qtd * sizeof(int));

    if(ptr == NULL){
        printf("Erro na alocação da memória");
        return;
    }

    for(int i = 0; i < qtd; i++){
        printf("Insira o numero %d -> ", i + 1);
        scanf("%d", (ptr + i));
    }

        maior = menor = *ptr;
    for(int i = 0; i < qtd; i++){
        if(*(ptr + i) > maior){
            maior = *(ptr+i);
        }

        if(*(ptr + i) < menor){
            menor = *(ptr + i);
        }
    }



    printf("\nMaior: %d\n", maior);
    printf("Menor: %d\n", menor);

    free(ptr);
    
}