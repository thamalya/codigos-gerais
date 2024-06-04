#include <stdio.h>

int main(){
    int N;
    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    if((N % 2) == 0){
        printf("%d eh um numero par!\n", N);
    }else{
        printf("%d eh um numero impar!\n", N);
    }

    return 0;
}