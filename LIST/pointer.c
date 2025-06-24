#include <stdio.h>
#include <stdlib.h>

void troca_end(int *a, int *b);

int main(){

    int *x, y = 5, z = 6;
    x = &y;
    printf("Endereco y: %#p\n",&y);
    printf("Endereco Z: %#p\n",&z);
    printf("x (antes): %#p\n",x);
    troca_end(x,&z);
    printf("x (DEPOIS): %#p\n",x);

    return 0;
}

void troca_end(int *a, int *b){
    a = b;
    printf("x (DENTRO): %#p\n",a);
}