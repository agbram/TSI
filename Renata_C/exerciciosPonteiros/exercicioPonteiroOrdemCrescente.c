#include <stdio.h>

void ordemCrescente(int *x, int y);

int main()
{
    int a[4] = {2, 4, 13, 8};

    ordemCrescente(a, 4);

    for(int i = 0; i < 4; i++)  {

    printf("[%d]", a[i]);
    
}
    return 0;
}

void ordemCrescente(int *x, int y) {
    int temp;

    for (int i = 0; i < y - 1; i++) {
        for (int j = i + 1; j < y; j++) {
            if (*(x + i) > *(x + j)) {
                temp = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = temp;
            }
        }
    }
}