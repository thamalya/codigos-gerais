#include <stdio.h>

int main(){
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    if(a > b){
        printf("%d eh maior do que %d!\n", a, b);
    }else{
        printf("%d eh maior do que %d!\n", b, a);
    }


    return 0;
}