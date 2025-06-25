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
/**
 * Insere um novo nó com o dado 'data' em uma 'position' específica da lista.
 * @param head Ponteiro para o ponteiro do início da lista.
 * @param position Índice onde o novo nó será inserido (começa em 0).
 * @param data O valor inteiro a ser armazenado no novo nó.
 */
void insertAtPosition(List* li, int position, int data) {
    // Valida a posição
    if (position < 0) {
        printf("Posição inválida. Deve ser 0 ou maior.\n");
        return;
    }

    // Cria o novo nó
    it* no;
    no = (it*) malloc(sizeof(it));
    no->value = data;

    if(no == NULL)
        return 0;

    // Caso especial: Inserção no início da lista (posição 0)
    if (position == 0) {
        no->next = (*li); // O novo nó aponta para o antigo início
        *li = no; // A cabeça da lista agora é o novo nó
        return;
    }

    // Percorre a lista até a posição ANTERIOR à de inserção
    it* var = (*li);
    int currentPosition = 0;
    while (var !=   NULL && currentPosition < position - 1) {
        var = var->next;
        currentPosition++;
    }

    // Se a posição for válida (nó anterior existe)
    if (var == NULL) {
        printf("Posição %d está fora do alcance da lista.\n", position);
        free(no); // Libera a memória do nó que não será usado
        return;
    }

    // Realiza a inserção ajustando os ponteiros
    no->next = var->next;
    var->next = no;
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