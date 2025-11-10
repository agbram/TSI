#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct pilha {
    char itens[MAX];
    int topo;
}  PILHA;

char simbolosAbertura[] = { '(','{','[' };
char simbolosFechamento[] = { ')','}',']' };

void testes();
void inicializarPilha(PILHA *p);
int isVazia(PILHA *p);
int isCheia(PILHA *p);
void empilhar(PILHA *p, char valor);
char desempilhar(PILHA*p);
int corresponde(char simbolosAbertura, char simbolosFechamento);
int verificaBalanco(char expressao[]);
int ehFechamento(char valor);
int ehAbertura(char valor);

int main(void){
    testes();
    return 0;
}

void testes(){
    
    printf("\n === Testes basicos === \n");
    char expressao1[] = {"{([({})])}"};
    char expressao2[] = {"([)]"};
    char expressao3[] = {"{[{"};
    char expressao4[] = {"])}"};
    char expressao5[] = {""};
    char expressao6[] = {"a + (b - c)"};

    printf("Expressao: %s -> %s\n", expressao1, verificaBalanco(expressao1)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressao2, verificaBalanco(expressao2)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressao3, verificaBalanco(expressao3)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressao4, verificaBalanco(expressao4)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressao5, verificaBalanco(expressao5)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressao6, verificaBalanco(expressao6)? "Balanceada" : "Desbalanceada");
    
    printf("\n === Testes com formulas matematicas === \n");
    char expressaoMat1[] = {"{([({a + b})])}"};
    char expressaoMat2[] = {"{[(x / 2) * ({y - 3})]}"};
    char expressaoMat3[] = {"{ [ (-b + sqrt(b^2 - 4*a*c)) / (2*a) ] }"};
    char expressaoMat4[] = {"{ [ (E = mc^2) ] ; ([ (F = m*a) ]) }"};
    char expressaoMat5[] = {"({a + b) * [c - d]}"};
    
    printf("Expressao: %s -> %s\n", expressaoMat1, verificaBalanco(expressaoMat1)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressaoMat2, verificaBalanco(expressaoMat2)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressaoMat3, verificaBalanco(expressaoMat3)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressaoMat4, verificaBalanco(expressaoMat4)? "Balanceada" : "Desbalanceada");
    printf("Expressao: %s -> %s\n", expressaoMat5, verificaBalanco(expressaoMat5)? "Balanceada" : "Desbalanceada");
}



void inicializarPilha(PILHA *p){
    p->topo = -1;
}

int isVazia(PILHA *p){
    return p->topo == -1;
}

int isCheia(PILHA *p){
    return p->topo == MAX - 1;
}

void empilhar(PILHA *p, char valor) {
    if (isCheia(p)) {
        printf("A pilha esta cheia... esvazie-a primeiro para poder empilhar %c.\n", valor);
    } else {
        p->itens[++(p->topo)] = valor;
    }
}

char desempilhar(PILHA *p){
    if(isVazia(p)){
        printf("A pilha esta vazia... popule-a primeiro para desempilhar.\n");
        return '\0';
    } else {
        return p->itens[(p->topo)--];
    }
}

int corresponde(char a, char b){
    for(int i = 0; i < 3; i++){
        if(a == simbolosAbertura[i] && b == simbolosFechamento[i])return 1;
        }
  return 0;
}

int ehAbertura(char valor) {
    for (int i = 0; i < 3; i++)
        if (valor == simbolosAbertura[i]) return 1;
    return 0;
}

int ehFechamento(char valor) {
    for (int i = 0; i < 3; i++)
        if (valor == simbolosFechamento[i]) return 1;
    return 0;
}

int verificaBalanco(char expressao[]){
    PILHA pilha;
    inicializarPilha(&pilha);
    char charDesempilhado;

    for(int i = 0; i < strlen(expressao); i++){
        char charAtual = expressao[i];

        if(ehAbertura(charAtual)){
            empilhar(&pilha, charAtual);
        } 
        else if(ehFechamento(charAtual)){
            if(isVazia(&pilha)){
                return 0;
            } else {
                charDesempilhado = desempilhar(&pilha);

                if(!corresponde(charDesempilhado, charAtual)){
                    return 0;
                }
            }
        }
    }
    return isVazia(&pilha);
}