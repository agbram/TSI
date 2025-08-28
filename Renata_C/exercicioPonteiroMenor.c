#include <stdio.h>

int menorValor(int *x, int y);

int main()
{
    int a[4] = {2, 4, 13, 8};

    int menor = menorValor(a, 4);

    printf("resultado: %d\n", menor);
    return 0;
}

int menorValor(int *x, int y)
{
    int menorValor = *x;

    for (int i = 0; i < y; i++)
    {   
        if(*(x+i) < menorValor){
        menorValor = *(x + i);
    }
}

    return menorValor;
}