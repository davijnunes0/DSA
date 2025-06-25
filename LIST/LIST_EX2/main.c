#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){

    printf("\n\n");

    // Declaração da lista
    List *li;
    // Inicialização da lista
    li = createList();

    // Adicionando elementos na lista:

    // Adicionando no início
    addInStart(li,2);
    // Adicionando no início
    addInStart(li,1);
    // Adicionando no final
    addInEnd(li,3);
    // Adicionando em uma posição específica
    addInPosition(li,10,1);
    printList(li);
    
    // Removendo elementos na lista:

    // Removendo no ínicio
    removeInStart(li);
    // Removendo no final
    removeInEnd(li);
    // Removendo um elemento específico
    removeElement(li,2);

    // Imprimindo a lista
    printList(li);

    // Verificando se um elemento está na lista
    searchElement(li,1);

    printf("\n\n");


}