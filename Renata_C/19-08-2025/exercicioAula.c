#include <stdio.h>

int main(){

    int numero = 50;
    int *ponteiro_numero;

    ponteiro_numero = &numero;

    printf("\nValor da variavel 'numero': %d\n", numero);
    printf("\nEndereco da variavel 'numero': %p\n", &numero);
    printf("\nValor do ponteiro 'ponteiro_numero'(endereco): %p\n", ponteiro_numero);
    printf("\nValor acessado pelo ponteiro 'ponteiro_numero': %d\n", *ponteiro_numero);

    return 0;

    
}