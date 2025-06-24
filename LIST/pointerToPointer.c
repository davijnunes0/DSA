#include <stdio.h>
#include <stdlib.h>

void troca_ender(int **a,int*b);

int main(){

    int **x, *w, y = 5, z = 6;
    x = &w;
    // Mesmo que w = &y
    *x = &y;

    printf("Endereco y: %#p\n",&y);
    printf("Endereco Z: %#p\n",&z);
    printf("x (antes): %#p\n",*x);
    troca_ender(x,&z);
    printf("x (DEPOIS): %#p\n",*x);
    printf("x value: %d\n",**x);

    return 0;
}

void troca_ender(int **a, int*b){
    // Troca para quem o endereço que está em **a aponta.
    *a = b;
    printf("X (Dentro): %#p\n",*a);
}
