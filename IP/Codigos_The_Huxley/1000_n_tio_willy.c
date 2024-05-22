#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long int n[1000];
    int cont_parar = 0;

    // Leitura dos números
    for (int i = 0; i < 1000; i++) {
        scanf("%lld", &n[i]);
        if (n[i] == -1) {
            break;
        }
        cont_parar++;
    }

    // Contagem de ocorrências
    long long int contador = 0;
    for (int i = 0; i < cont_parar; i++) {
        if (N == n[i]) {
            contador++;
        }
    }

    if (contador > 0) {
        printf("%d aparece %lld vezes", N, contador);
    } else {
        printf("%d nao aparece", N);
    }
    return 0;
}
