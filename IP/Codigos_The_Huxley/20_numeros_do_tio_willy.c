#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int n[20];

    int  contador = 0;
    int cont_parar = 0;

    for(int i = 0;n[i] == -1 || cont_parar >= 20; i++){
        scanf("%d", &n[i]);
        cont_parar++;
    }

    for(int i = 0; i < cont_parar; i++){
        if(N == n[i]){
            contador++;
        }
    }

    printf("%d aparece %d vezes", N, contador);
    return 0;
}