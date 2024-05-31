#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome_musica[20];
    int estado_do_CD;
    char classificacao[20];
}Album;

typedef struct{
    char nome_artista[20];
    Album musicas;
}Artista;

int main(){
    int N;
    int M;
    scanf("%d", &N);
    Artista artista[N];
    Album albuns[M];
    
    for(int i = 0; i < N; i++){
        scanf(" %19[^\n]", artista[i]); scanf("%d", &M);
        for(int j = 0; j < M; j++){
            scanf(" %19[^\n]", albuns[j].nome_musica); scanf("%d", &albuns[j].estado_do_CD);
            scanf(" %19[^\n]", albuns[j].classificacao);
        }
        
    }


    return 0;
}