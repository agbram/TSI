#include <stdio.h>
#include <stdlib.h>

void aloca();

int main()
{
    aloca();

    return 0;
}

void aloca()
{

    int qtd;
    float *ptr;
    float soma = 0;
    float media;

    printf("Quantos numeros deseja? ");
    scanf("%d", &qtd);

    ptr = (float *)malloc(qtd * sizeof(float));

    if (ptr == NULL)
    {
        printf("Erro na alocação da memória!");
        return;
    }

    for (int i = 0; i < qtd; i++)
    {
        printf("Insira o numero %d: ", i+1);
        scanf("%f", (ptr + i));
        soma += *(ptr + i);
    }

    media = soma / qtd;

    printf("Media dos números é: %.2f ", media);

    free(ptr);
}
