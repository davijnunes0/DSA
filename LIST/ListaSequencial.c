#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
// Definição do tipo de lista
struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){

    //  Define o ponteiro do tipo Lista
    Lista *li;

    // Aloca a memória necessária para utilização dessa struct
    li = (Lista*) malloc(sizeof(struct lista));

    // Verifica se é NULL, caso não for inicializa a quantidade de alunos
    if(li != NULL){
        li->qtd = 0;
    }

    // Retorna a lista
    return li;
}

// Libera a memória alocada para a lista
void libera_lista(Lista* li){
    free(li);
}

// Retorna o tamanho da lista.
int tamanho_lista(Lista* li){
    if(li == NULL){
        return -1;
    }

    return li->qtd; // quantidade de alunos
}

// Verifica se a lista está cheia.
int lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == MAX);
}
// Verifica se a lista está vazia
int lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == 0);
}

// Inserir no início do array
int insere_lista_inicio(Lista *li, struct aluno al){

    if(li == NULL)
        return 0;
    else if(li->qtd == MAX) // lista cheia
        return 0;
    
    int i;
    for(i = li->qtd -1; i>=0; i--){
        li->dados[i+1] = li->dados[i];
     }

     li->dados[0] = al;
     li->qtd++;
     return 1;
}

// Inserir no final da lista 
int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    
    if(li ->qtd == MAX) // Lista cheia
        return 0;
    
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordernada(Lista* li, struct aluno al){

    if(li == NULL)
        return 0;
    else if(li ->qtd == MAX) // Lista cheia
        return 0;
    
    int k,i = 0;

    /*
        Enquanto i < quantidade de alunos é matricula for menor que a matricula do aluno atual.
        i = posição que vamos inserior
    */
    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }

    // Iremos deslocar os elementos até chegarmos na posição em que queremos inserir.
    for(k= li->qtd-1; k >= i; k--){
        li->dados[k+1] = li->dados[k];
    }

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

// Removendo elemento no ínicio da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    
    if(li->qtd == 0) // Lista vazia
        return 0;
    
    int k = 0;

    for(k = 0; li->qtd-1; k++){
        /*
            A posição atual de k irá receber o próximo elemento.
            Como k = 0, a posição zero irá receber o elemento no índice[1];
        */
        li->dados[k] = li->dados[k + 1];
    }

    li->qtd--;
    return 1;
}

// Remove no final da lista
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd = 0) // Lista vazia
        return 0;

    // Removendo o acesso ao elemento que está no indice final.
    li->qtd--;
    return 1;
}

// Removendo um elemento específico da lista 
int remove_lista(Lista* li, int mat){

    if(li == NULL)
        return 0;
    if(li->qtd == 0) // Lista vazia
        return 0;
    
    int k,i = 0;

    // Procura o aluno que tem a matricula passada pelo usuário
    while(i<li->qtd  && li->dados[i].matricula != mat){
        i++;
    }

    // Verifica se o aluno foi encontrado
    if(i == li->qtd)
        return 0 ;

    for(k = i; k<= li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }

    li->qtd--;

    return 0;

}