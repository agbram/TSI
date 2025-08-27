// Crie uma função que recebe um número inteiro e um
// ponteiro para um número inteiro. A função deve dobrar o
// valor do primeiro número e triplicar o valor para o qual o
// ponteiro aponta.
// ● Explique em que situações a passagem por valor é mais
// segura e quando a passagem por referência é mais
// eficiente.
#include <stdio.h>

int dobra_triplica(int x, int *ptr);

int main(){
    int a = 2;
    int b = 4;
    
    printf("== Before ===\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);


    a = dobra_triplica(a,&b);

    printf("== After ==\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}

int dobra_triplica(int x,int *ptr){
    
    *ptr = *ptr * 3;

    return x * 2;
}