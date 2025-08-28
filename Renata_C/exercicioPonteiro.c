#include <stdio.h>

int get_sum(int *x, int y);

int main()
{
    int a[4] = {2, 4, 6, 8};

    int soma = get_sum(a, 4);

    printf("resultado: %d\n", soma);
    return 0;
}

int get_sum(int *x, int y)
{
    int soma = 0;
    for (int i = 0; i < y; i++)
    {
        soma += *(x + i);
    }

    return soma;
}