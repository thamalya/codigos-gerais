#include <stdio.h>

void calcular_media (int *A, int *B){
    int media = (*A + *B)/2;
    if(*A < *B){
        *B = (*A + *B) % 2;
        *A = media;
    }else if(*B < *A){
        *A = (*A + *B) % 2;
        *B = media;
    }
}

int main(){
    int A, B;
    scanf("%d%d", &A, &B);

    calcular_media(&A, &B);
    printf("A = %d\nB = %d", A, B);

    return 0;
}