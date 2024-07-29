#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int ano_nascimento;
    char CPF[12];
}Autor;

typedef struct{
    char titulo[100];
    char ISBN[20];//cod unico para cada livro
    Autor *autores;
    int qtd_autores;
}Livro;

Livro *NovoLivro(Livro *biblioteca, int *tam){//adicionando o livro na biblioteca
    Livro tmp_livro;
    char escolha;
    
    do{
        printf("Digite o nome do livro: ");
        scanf(" %99[^\n]", tmp_livro.titulo);
        printf("Digite o codigo do livro(ISBN): ");
        scanf(" %19[^\n]", tmp_livro.ISBN);

        tmp_livro.autores = NULL;
        tmp_livro.qtd_autores = 0;

        biblioteca = (Livro *) realloc(biblioteca, (*tam+1) * sizeof(Livro));
        if(biblioteca == NULL){
            printf("Erro de alocacao!\n");
            exit(1);
        }

        biblioteca[*tam] = tmp_livro;
        (*tam)++;

        printf("Deseja adicionar outro livro?(s/n)\n");
        scanf(" %c", &escolha);
    }while(escolha != 'n');

    return biblioteca;
}
void Inserir(Livro *biblioteca, int tam){//nao consegui fazer funcionar
    char ISBN_temp[20];
    int encontrado = 0;
    Autor autor_tmp;

    printf("Insira o ISBN do livro: ");
    scanf(" %19[^\n]", ISBN_temp);

    for(int i = 0; i < tam; i++){
        if(strcmp(ISBN_temp, biblioteca[i].ISBN) == 0){
            encontrado = 1;

            printf("Digite o nome do autor: ");
            scanf(" %49[^\n]", autor_tmp.nome);
            
            printf("Digite o ano de nascimento do autor: ");
            scanf("%d", &autor_tmp.ano_nascimento);
            
            printf("Digite o CPF do autor: ");
            scanf(" %11[^\n]", autor_tmp.CPF);
            
            biblioteca[i].autores = (Autor *) realloc(biblioteca[i].autores, (biblioteca[i].qtd_autores+1) * sizeof(Autor));
            if(biblioteca[i].autores == NULL){
                printf("Erro de alocacao!\n");
                exit(1);
            }
            
            biblioteca[i].autores[biblioteca[i].qtd_autores] = autor_tmp;
            biblioteca[i].qtd_autores++;
            
            printf("\nAutor cadastrado com sucesso!\n");
            
            return;
        }
    }
    
    if(!encontrado){
        printf("Livro nao encontrado!\n");
    }
}
void Procura(Livro *biblioteca, int tam){//nao consegui fazer funcionar com o nome, mas se voce mudar pra procurar livro pelo  cooodigo ISBN... funciona ajskaks
    char nome_autor[50];
    printf("\n\nDigite o nome do autor: \n");
    scanf(" %49[^\n]", nome_autor);
    
    int encontrado = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(strcmp(biblioteca[i].autores[j].nome, nome_autor) == 0){
                printf("Livro encontrado: %s\n", biblioteca[i].titulo);
                encontrado = 1;
            }
        }
    }
    
    if(!encontrado){
        printf("Nenhum livro deste autor encontrado!\n");
    }
}
void ExibeBiblioteca(Livro *biblioteca, int tam){//exibindo os livros existentes
    printf("\n\n-----Livros Existentes-----\n");
    for(int i = 0; i < tam; i++){
        printf("Titulo: %s\n", biblioteca[i].titulo);
        for(int j = 0; j < biblioteca[i].qtd_autores; j++){
            printf("Autor: %s\n", biblioteca[i].autores[j].nome);
            printf("Ano de Nascimento: %d\n", biblioteca[i].autores[j].ano_nascimento);
            printf("CPF: %s\n", biblioteca[i].autores[j].CPF);
            printf("\n");
        }
    }
    printf("\n");
}

void Desaloca(Livro *biblioteca, int tam){
    for(int i = 0; i < tam; i++){
        free(biblioteca[i].autores);
    }
    free(biblioteca);
    printf("\n\nPonteiros liberados com sucesso!\n");
}

int main(){
    Livro *ptr_livro = NULL;
    int qtd = 0;
    int escolha = -1;

    printf("\n\n-----MENU-----\n");//menuzinho
    do{
        printf("O que deseja fazer?\n");
        printf("1.Novo Livro\n2.Inserir Autor\n3.Procurar Livro\n4.Exibir Biblioteca\n5.Liberar ponteiros\n6.Sair");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                ptr_livro = NovoLivro(ptr_livro, &qtd);
            break;

            case 2:
                Inserir(ptr_livro, qtd);
            break;

            case 3:
                Procura(ptr_livro, qtd);
            break;

            case 4:
                ExibeBiblioteca(ptr_livro, qtd);
            break;

            case 5:
                Desaloca(ptr_livro, qtd);
            break;

            default:
                printf("\n\nEscolha uma opcao valida!\n");
            break;
        }

    }while(escolha != 6);

    free(ptr_livro);

    return 0;
}
