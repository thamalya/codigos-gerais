#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cpf[12];
    float *notas;
    int qtdNotas;
}Aluno;

Aluno *carregarAlunos(int *qtdAlunos){
    char temMaisAlunos;
    Aluno aluno;
    Aluno *cadAlunos = NULL;

    *qtdAlunos = 0;

    do{
    printf("Digite o nome do aluno: ");
    scanf(" %99[^\n]", aluno.nome);
    printf("Digite o cpf do aluno: ");
    scanf(" %11[^\n]", aluno.cpf);

    cadAlunos = (Aluno *) realloc(cadAlunos, (*qtdAlunos + 1) * sizeof(Aluno));
    if(cadAlunos == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    cadAlunos[*qtdAlunos] = aluno;
    (*qtdAlunos)++;

    printf("Tem mais alunos?(s/n)");
    scanf(" %c", &temMaisAlunos);

    }while(temMaisAlunos != 'n');

    return cadAlunos;
}

int main(){
    int qtdAlunos;

    Aluno *turma = carregarAlunos(&qtdAlunos);

    for(int i = 0; i < qtdAlunos; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", turma[i].nome);
        printf("CPF: %s\n", turma[i].cpf);
    }


    return 0;
}