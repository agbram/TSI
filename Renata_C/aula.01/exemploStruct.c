    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>

    typedef struct
    {
    int ano;
    int mes;
    int dia;
    } Data;

    void mudaDia(int *x,int *y,int *z);


    int main(){
    Data data;
    data.dia = 30;
    data.mes = 12;
    data.ano = 2025;

    int opcao;

    do{

    system("cls");

    printf("== Current Data ==\n");
    printf(" %d / %d / %d \n", data.dia, data.mes, data.ano);

    mudaDia(&data.dia,&data.mes,&data.ano);

    printf("== With alterations ==\n");
    printf(" %d / %d / %d \n", data.dia, data.mes, data.ano);
    
    printf("Mudar mais alguma coisa?\n");
    printf("1. SIM\n");
    printf("0. NAO\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    }while(opcao != 0);

    printf("== Final Data ==\n");
    printf(" %d / %d / %d \n", data.dia, data.mes, data.ano);

    printf("Encerrando... Obrigado por usar o sistema!\n");

    Sleep(3*1000);

    system("cls");

    return 0;
    }

    void mudaDia(int *x,int *y,int *z){

        int opcao;
        do{
        printf("Qual valor que quer mudar da Data: \n");
        printf("1. Dia\n");
        printf("2. Mes\n");
        printf("3. Ano\n");
        printf("Escolha a opcão: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Quer mudar para qual dia?\n");
            scanf("%d", &*x);
            system("cls");
        } else if(opcao == 2){
            printf("Quer mudar para qual mes?\n");
            scanf("%d", &*y);
            system("cls");
        } else if(opcao == 3){
            printf("Quer mudar para qual ano?\n");
            scanf("%d", &*z);
            system("cls");
        } else {
            printf("Tentativa inválida...\n");
        }
    }while(opcao > 3 || opcao < 1);
        
    }
