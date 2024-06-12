#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x, y;//posicao inicial no mapa
    char mensagem[100];
    char caminho[100];
}Pedido;

Pedido criarPedido(){
    Pedido p;

    printf("Digite a posicao inicial: ");
    scanf("%d %d", &p.x, &p.y);

    printf("Digite a mensagem: ");
    scanf(" %99[^\n]", p.mensagem);

    printf("Digite o caminho: ");
    scanf(" %99[^\n]", p.caminho);

    return p;
}

void atualizarMatriz(char matriz[][100], int M, Pedido p) {
    int x = p.x, y = p.y;
    matriz[x][y] = 'x'; // posição inicial

    for (int i = 0; p.caminho[i] != '\0'; i++) {
        switch (p.caminho[i]) {
            case 'N': x--; break;
            case 'S': x++; break;
            case 'L': y++; break;
            case 'O': y--; break;
        }
        if (p.caminho[i + 1] != '\0') {
            matriz[x][y] = '*'; // caminho intermediário
        } else {
            matriz[x][y] = '&'; // posição final
        }
    }
}

int main(){
    int N, M;

    printf("Digite o numero de pedidos a serem feitos: ");
    scanf("%d", &N);

    Pedido pedidos[N];

    for(int i = 0; i < N; i++){
        pedidos[i] = criarPedido();
    }

    printf("Digite a dimensao MxM do mapa: ");
    scanf("%d", &M);

    char matriz[M][M];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            matriz[i][j] = '-';
        }
    }

 for (int i = 0; i < N; i++) {
        atualizarMatriz(matriz, M, pedidos[i]);
    }

    printf("Mapa final:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}