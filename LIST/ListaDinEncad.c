#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

struct elemento{
    struct aluno dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    // sizeof(LIsta) = sizeof(struct elemento*) 
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
    // Inicializando o ponteiro para ponteiro com NULL
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int tamanho_lista(Lista* li){
    
    if(li == NULL)
        return 0;
    
    int cont = 0;
    Elem* no = *li;

    while(no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    else if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    (*li) = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){

    // Verificamos se a lista está vazia
    if(li == NULL)
        return 0;
    
    // Declaramos um ponteiro do tipo elemento
    Elem* no;
    // Alocamos memória
    no = (Elem*) malloc(sizeof(Elem));

    // Verificamos se  o nó foi alocado corretamente
    if(no == NULL)
        return 0;
    
    // Atribuimos os dados
    no->dados = al;
    // O ponteiro do ponteiro vai apontar para null;
    no->prox = NULL;

    if(*(li) == NULL) // Lista vazia: Insere no íncio
        *li = no;
    else{
        // Variável auxiliar
        Elem *aux;
        // Pegamos a head da lista
        aux = *li;

        // Percorremos até chegar no final da lista
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        // Inserimos no ponteiro que aponta para NULL
        aux->prox = no;
    }

    return 1;
}

int print_aluno(Lista* li){

    // Verificação se a lista foi inicializada
    if(li == NULL){
        return 0;
    }

    // Verificação se a lista está apontando para algum endereço
    if((*li) == NULL){
        return 0;
    }

    // Pegamos a cabeça da lista
    Elem *aux = (*li);

    // Percorremos todos os elementos da lista é imprimimos os dados
    while(aux != NULL){
        printf("Nome: %s, matricula: %d,(n1= %.2lf, n2= %.2lf,n3= %.2lf)\n",
        aux->dados.nome,aux->dados.matricula,aux->dados.n1,aux->dados.n2,aux->dados.n3);
        aux = aux->prox;
    }
}

