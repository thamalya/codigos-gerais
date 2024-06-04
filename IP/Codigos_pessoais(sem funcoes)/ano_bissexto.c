#include <stdio.h>

int main(){
    int ano;
    printf("Digite um ano valido: ");
    scanf("%d", &ano);

    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        printf("%d eh um ano bissexto!\n", ano);
    }else{
        printf("%d nao eh um ano bissexto!\n", ano);
    }

    return 0;
}