#include <stdio.h>
#include <stdlib.h>
#include "listTad.h"

struct item{
    int value;
    struct item* next;
};

typedef struct item it;

List* createList(){
    // Criamos a lista
    List* li = (List*) malloc(sizeof(List));

    // Se li foi inicializado corretamente ela irá apontar para nulo
    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void freeList(List* li){

    if(li != NULL){
        it* no;

        // Enquanto o elemento que li -> aponta for diferente de nulo
        while((*li) != NULL){
            no = *li;
            *li = (*li)->next;
            free(no);
        }

        free(li);
    }
}

int insertStart(List* li, int number){

    // Verifica se a lista está vazia
    if(li == NULL)
        return 0;

    // Declara um ponteiro que aponta para uma struct item
    it* no;
    // Aloca a memória
    no = (it*) malloc(sizeof(it));

    // Verifica se foi alocado corretamente
    if(no == NULL)
        return 0;

    // Atribuindo valor
    no->value = number;
    // O novo nó aponta para o antigo elemento
    no->next = (*li);
    // O antigo elemento vira o primeiro elemento
    *li = no;

    return 1;
}

int insertEnd(List* li, int number){

    // Verificando se a lista está vazia
    if(li == NULL){
        return 0;
    }

    
    it* no;
    no = (it*) malloc(sizeof(it));

    if(no == NULL)
        return 0;

    no->value = number;
    no->next = NULL;

    if((*li) == NULL){
        *li = no;
    }else{
        it* aux;
        aux = *li;
        while(aux->next != NULL){
            aux = aux->next;
        }   
        
        aux->next = no;
    }

    return 1;
}

int printList(List* li){

    if(li == NULL){
        return 0;

    }

    if((*li) == NULL){
        return 0;
    }

    printf("\n");
    it* aux = (*li);

    while(aux != NULL){
        printf("%d->",aux->value);
        aux = aux->next;
    }

    printf("\n");

    return 1;

}

// Retorna o tamanho da lista
int size(List* list){

    if(list == NULL)
        return 0;
    
    int cont = 0;
    it *no = *(list);

    while(no != NULL){
        cont = cont + 1;
        no = no->next;
    }
    return cont;


}