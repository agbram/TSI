#include <stdio.h>

int main(){

    int valor = 100;
    int *p_valor;

    p_valor = &valor;

    printf("Valor antes da mudança: %d\n", valor);

    //usamos o ponteiro para mudar o valor da variavel "valor"
    *p_valor = 200;

    printf("Valor depois da mudança: %d\n", valor);
    printf("Valor acessado pelo ponteiro: %d\n", *p_valor);

    return 0;
}