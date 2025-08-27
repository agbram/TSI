#include <stdio.h>

void mudanca(int *x, int y);

int main(){
    int a[] = {1, 2 , 3, 4 , 5};
    int b = 5;
    
    printf("== Before ===\n");
    for(int i = 0; i < b; i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    
    mudanca(a,b);

    printf("== After ==\n");
    for(int i = 0; i < b; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}

void mudanca(int *x,int y){
    
    for(int i = 0; i < y; i++){
        x[i] = x[i] * 2; 
    }
}