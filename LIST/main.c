#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#include <string.h>

int main(){


    Lista* li = cria_lista();
    printf("Quantidade: %d\n",tamanho_lista(li));

    struct aluno al;
    al.matricula = 20250101;
    strcpy(al.nome,"Maria Fernanda");
    al.n1 = 10.0;
    al.n2 = 9.5;
    al.n3 = 10.0;

    insere_lista_inicio(li,al);
    printf("Quantidade: %d\n",tamanho_lista(li));


    return 0;

}