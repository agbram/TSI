#include <stdio.h>

void inverteArray(int *x, int y);

int main()
{
    int a[4] = {2, 4, 13, 8};

    inverteArray(a, 4);

    for(int i = 0; i < 4; i++)
{
    printf("[%d]", a[i]);
}    
    return 0;
}

void inverteArray(int *x, int y)
{
    int *pInicio = x;          // ponteiro para o primeiro elemento
    int *pFim = x + y - 1;     // ponteiro para o último elemento
    int aux;

    while (pInicio < pFim)     // troca até os ponteiros se cruzarem
    {
        aux = *pInicio;
        *pInicio = *pFim;
        *pFim = aux;

        pInicio++;  // avança o início
        pFim--;     // recua o fim
    }
}
