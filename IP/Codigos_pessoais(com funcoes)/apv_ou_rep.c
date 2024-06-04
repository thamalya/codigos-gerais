#include <stdio.h>

float calcularMedia(float n1, float n2, float n3){
    float media = (n1 + n2 + n3) / 3;

    return media;
}

void lerNotas(float *nota1, float *nota2, float *nota3){
    printf("Digite as 3 notas: ");
    scanf("%f %f %f", nota1, nota2, nota3);
}

int main(){
    float nota1, nota2, nota3;
    lerNotas(&nota1, &nota2, &nota3);
    float media;
    
    media = calcularMedia(nota1, nota2, nota3);

    printf("A media eh: %.2f", media);

    return 0;
}