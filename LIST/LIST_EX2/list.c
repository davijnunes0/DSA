#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Definção da estrutura
struct element{
    int data;
    struct element* next;
};

// Dando outro aliases para struct
typedef struct element Elem;

// Função responsável por criar uma lista 
List* createList(){

    // ALocando memória para a 
    // List* li = (List*) malloc(sizeof(List));   = List* li = (List*) malloc(sizeof(struct elemento*));
    List* li = (List*) malloc(sizeof(List));   

    // Inicializando o nó que a lista aponta
    if(li != NULL){
        // Se a lista tiver sido alocada corretamente iremos apontar para NULL
        *li = NULL;
    }

    // Iremos retornar a lista
    return li;
}
// Função responsável por liberar os nó de uma lista
int freeList(List* li){

    // Verificação
    if(li == NULL || (*li) == NULL) return 0;

    Elem* no;

    while((*li) != NULL){
        // Recebe o primeiro nó da lista
        no = *li;
        // Vamos para o nó seguinte da lista
        *li = no->next;
        // Liberamos o nó
        free(no);
    }

    // Liberamos a lista
    free(li);
     return 1;  // Adicionado retorno de sucesso

}

// Função que irá adicionar no início da lista
int addInStart(List* li, int data){

    // Verificando se a lista foi alocada corretamente
    if(li == NULL)
        return 0;
    
    // Declaramos o nó
    Elem* no;
    // Alocamos memória
    no = (Elem*) malloc(sizeof(Elem));

    // Verificamos se foi alocado corretamente
    if(no == NULL)
        return 0;
    
    // Atribuiremos o valor para o novo nó instânciado na memória
    no->data = data;

    // Faremos o novo nó atual apontar para o antigo primeiro elemento
    no->next = (*li);

    // O primeiro nó irá virar o novo nó instânciado
    (*li) = no; 

    // Caso funcionar iremos retornar 1;
    return 1;
}

int addInEnd(List* li, int data){

    // Verificando se a lista foi alocada corretamente.
    if(li == NULL)
        return 0;
    
    // Declaração do novo nó
    Elem * no;
    // ALocação de memória do novo nó
    no = (Elem*) malloc(sizeof(Elem));

    // Verifica se o nó foi alocado corretamente
    if(no == NULL)
        return 0;

    // Atribuindo o novo valor de nó
    no->data = data;
    // Como vai ser o último nó de uma lista simplesmente encadeada iremos apontar para NULL.
    no->next = NULL;

    // Caso a lista for vazia
    if((*li) == NULL){
        (*li) = no;
        return 1;
    }else{

        // Declarando a variável auxiliar
        Elem* var;
        // Atribuindo primeiro elemento da lista
        var = (*li);

        // Procurando o último nó
        while(var->next != NULL){
            var = var->next;
        }

        // Inserindo no final da lista
        var->next = no;
        return 1;
    }

}
int addInPosition(List* li, int data, int pos){
    // 1. Verificação iniciais
    if(li == NULL || pos <= 0)
        return 0;

    // Aloca o novo nó
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0; // Caso a alocação do novo nó não tenha funcionado.
    
    // Atribuindo o dado corretamente
    no->data = data;

    // 2. Caso especiaç: Inserção no início (pos == 1)
    if(pos == 1){
        no->next = (*li); // O novo nó aponta para o antigo primeiro
        *li = no; // A cabeça da lista agora é o novo npo
        return 1;
    }

    // 3. Caso geral: Inserção no meio ou fim.
    // Precisamos encontrar o nó ANTERIOR (na posição pos -1)
    Elem* anterior = (*li);
    int contador = 1;
    while(contador < pos - 1 && anterior != NULL){
        anterior = anterior->next;
        contador++;
    }

    // 4. Verificação de Posição Inválida (Além do tamanho da lista)
    // Se "anterior for NULL", a posição pedida não existe.
    if(anterior == NULL){
        free(no); // Posição Inválida
        return 0;
    }
    // 5. Realiza a cirurgia de  ponteiros
    no->next = anterior->next; // Passo 1: da lógica
    anterior->next = no; // Passo 2: da lógica 

    return 1; // Sucesso

}

int removeInStart(List* li){
    // 1- Verifica se a lista foi alocada corretamente.
    // 2- Verifica se a lista aponta para alguem.
    if(li == NULL || (*li) == NULL) return 0;

    // Pegamos o primeiro elemento da lista
    Elem* no = (*li);
    // Fazemos a lista apontar para o nó seguinte ao primeiro da lista
    *li = no->next;
    // Desalocando a memória que usamos para esse nó
    free(no);
    return 1;
}
int removeInEnd(List* li){

    // 1- Verifica se a lista foi alocada corretamente.
    // 2- Verifica se a lista aponta para alguem.
    if(li == NULL || (*li) == NULL) return 0;
    
    // Pegamos o primeiro elemento da lista
    Elem *no = (*li);
    Elem *ant = NULL;
    
    // Chegando ao ultimo elemento da lista
    while(no->next != NULL){
        ant = no;
        no = no->next;
    }

    /*
        Se nó também e o início da lista, então o início da lista deverá apontar para a posição seguinte a ele, que
        nesse caso é null, lista irá ficar vazia.
    */
    if(no == (*li)){
        *li = no->next;
        return 1;
    }else{
        /*
            Caso contrário, penúltilmo elemento da lista (ant) irá apontar para o elemento seguinte ao nó (último) nó.
        */
        ant->next = no->next;
        return 1;
    }

    // Liberando a memporia do nó
    free(no);

}

int removeElement(List* li, int data){

    // 1- Verifica se a lista foi alocada corretamente.
    // 2- Verifica se a lista aponta para alguem.
    if(li == NULL || (*li) == NULL) return 0;
    
    // Pegamos o primeiro elemento da lista
    Elem *no = (*li) ;
    Elem *ant = NULL;

    // Chegando ao elemento que tem o dado que queremos remover.
    while(no != NULL && no->data != data){
        ant = no;
        no = no->next;
    }

    if(no == NULL) // Caso o elemento não foi encontrado
        return 0;

    // Caso seja o primeiro elemento da lista
    if(no == (*li)){
        // *li = recebe o nó seguinte ao que o nó antigo apontava.
        *li = no->next;
    }else{
        // ant->next = recebe 0 nó seguinte ao que o nó antigo apontava.
        ant->next = no->next;
    }

    free(no);
    return 1;
}

// Função que busca um elemento específico
int searchElement(List* li, int data){

    // Verificações:
    //1. Se a lista foi alocada corretamente.
    //2. Se a lista aponta para alguem.
    if(li == NULL || (*li) == NULL)
        return 0;
    
    // Pegando a cabeça da lista
    Elem* no = (*li);

    // Percorrendo até o último nó e enquanto não encontrarmos nossos dados.
    while(no != NULL && no->data != data){
        no = no->next;
    }

    if(no == NULL) printf("Elemento não encontrado!\n");
    else printf("O elemento %d foi encontrado com sucesso",no->data);    

}
// Função que imprime os elementos da lista
int printList(List* li){

    // Verificações:
    //1. Se a lista foi alocada corretamente.
    //2. Se a lista aponta para alguem.
    if(li == NULL || (*li) == NULL)
        return 0;

    // Pegando o elemento inícial da lista
    Elem* no = (*li);

    while(no != NULL){
        printf("%d->",no->data);
        no = no->next;
    }

    printf("\n");
    return 1;

}