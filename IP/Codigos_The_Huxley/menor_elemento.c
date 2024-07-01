#include <stdio.h>

int maiorValor(int *array, int tamanho){
    int max = array[0];
    for(int i = 1; i < tamanho; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
};

int menorValor(int *array, int tamanho){
    int min = array[0];
    for(int i = 1; i < tamanho; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
};

int main(){
    int array[6];
    
    for(int i = 0; i < 6; i++){
        scanf("%d", &array[i]);
    }

    int max = maiorValor(array, 6);
    int min = menorValor(array, 6);

    printf("%d\n%d", min, max);

    return 0;
}