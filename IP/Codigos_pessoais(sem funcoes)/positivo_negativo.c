#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    if(N > 0){
        printf("O numero %d eh positivo\n", N);
    }else{
        printf("O numero %d eh negativo\n", N);
    }

    return 0;
}