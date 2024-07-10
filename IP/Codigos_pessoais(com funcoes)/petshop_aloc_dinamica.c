#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome_cachorro[50];
    char raca_cachorro[50];
    int idade_cachorro;
}PetShop;

PetShop *registrarAnimal(int *qtd_pets){
    PetShop pets;
    PetShop *cadPets = NULL;
    char escolha;
    
    *qtd_pets = 0;
    
    do{
        printf("Nome do pet: "); scanf(" %49[^\n]", pets.nome_cachorro);
        printf("Raca do pet: "); scanf(" %49[^\n]", pets.raca_cachorro);
        printf("Idade do pet: "); scanf("%d", &pets.idade_cachorro);
        
        cadPets = (PetShop *) realloc(cadPets, (*qtd_pets + 1) * sizeof(PetShop));
        if(cadPets == NULL){
            printf("Erro ao alocar memoria!\n"); exit(1);
        }
        
        cadPets[*qtd_pets] = pets;
        (*qtd_pets)++;
        
        printf("Gostaria de adicionar outro pet?(s/n)");
        scanf(" %c", &escolha);
        
    }while(escolha != 'n');
    
    return cadPets;
}

void ordena(PetShop *clientes, int qtd_pets){
    PetShop pets;
    
    for(int i = 0; i < qtd_pets-1; i++){
        for(int j = 0; j < qtd_pets-i-1; j++){
            if(strcmp(clientes[j].nome_cachorro, clientes[j + 1].nome_cachorro) > 0){
                pets = clientes[j+1];
                clientes[j+1] = clientes[j];
                clientes[j] = pets;
            }
        }
    }
}

PetShop *removerAnimal(PetShop *clientes, int *qtd_pets){
    int index = -1;
    int i;
    char nome[50];
    printf("Digite o nome do animal que deseja remover: ");
    scanf(" %49[^\n]", nome);
    
    for(i = 0; i < *qtd_pets; i++){
        if(strcmp(clientes[i].nome_cachorro, nome) == 0){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        printf("Cachorro nao encontrado!\n");
        return clientes;
    }
    
    for(int index = 0; i < *qtd_pets - 1; i++){
        clientes[i] = clientes[i+1];
    }
    *qtd_pets -= 1;
    clientes = (PetShop *) realloc(clientes, (*qtd_pets) * sizeof(PetShop));
    if(*qtd_pets > 0 && clientes == NULL){
        printf("Erro ao realocar memoria!\n"); exit(1);
    }
    
    return clientes;
}

int main() {
    PetShop *clientes;
    int qtd_pets;
    
    clientes = registrarAnimal(&qtd_pets);
    ordena(clientes, qtd_pets);
    printf("\nAntes da remocao:\n");
     for (int i = 0; i < qtd_pets; i++) {
        printf("Nome: %s, Raca: %s, Idade: %d\n", clientes[i].nome_cachorro, clientes[i].raca_cachorro, clientes[i].idade_cachorro);
    }
    
    removerAnimal(clientes, &qtd_pets);
    printf("\nDepois da remocao:\n");
     for (int i = 0; i < qtd_pets; i++) {
        printf("Nome: %s, Raca: %s, Idade: %d\n", clientes[i].nome_cachorro, clientes[i].raca_cachorro, clientes[i].idade_cachorro);
    }
    
    free(clientes);

    return 0;
}