#include <stdio.h>

int maiorValor(int *x, int y);

int main()
{
    int a[4] = {2, 4, 13, 8};

    int maior = maiorValor(a, 4);

    printf("resultado: %d\n", maior);
    return 0;
}

int maiorValor(int *x, int y)
{
    int maiorValor = *x;

    for (int i = 0; i < y; i++)
    {   
        if(*(x+i) > maiorValor){
        maiorValor = *(x + i);
    }
}

    return maiorValor;
}