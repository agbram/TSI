#include <stdio.h>
void cuboPorReferencia(int *nPtr); /* protótipо */
int main(void)
{
    int number = 5; /* inicializa número */
    printf("0 valor original do numero é %d", number);
        /* passa endereço do número a cuboPorReferencia */
        cuboPorReferencia(&number);
    printf("\n0 novo valor do numero é %d\n", number); return 0; /* indica conclusão bem-sucedida */
} /* fim do main */
/* calcula cubo de *nPtr; modifica variável number em main */
void cuboPorReferencia(int *nPtr)
{
*nPtr = *nPtr * *nPtr * *nPtr; /* cubo de *nPtr */
} /* fim da função cuboPorReferencia */