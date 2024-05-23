#include <stdio.h>

typedef struct{
    char nome[50];
    float presenca;
    int notas_matematica[3];
    int notas_portugues[3];
    int notas_historia[3];
}Aluno;

typedef struct{
    int id;
    int aprovados;
}Sala;

int calcularMedia(int nota1, int nota2, int nota3){
    return (nota1 + nota2 + nota3) / 3;
}

int verificarAprovacao(){

}

Aluno inserindoAlunos(){

}

int main(){
    int n;
    scanf("%d", &n);

    Sala salas[n];

    for(int i = 0; i < n; i++){
        
    }

    return 0;
}