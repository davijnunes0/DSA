#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *V, int N, int elem);
int buscaOrdenada(int *V, int N, int elem);
int buscaBinaria(int *V, int N, int elem);
    /** 
     * Busca: 
     *      Recuperação de dados armazenados em um repositório ou "base de dados"
     * Tipo de buscca depende dos dados:
     *      Dados estão estrutrurados (vetor, lista, árvore). Existem também busca em dados não estruturados
     *      Dados ordenados (ou não ordenados) valores duplicados.
     * Métodos:
     *      Busca Linear
     *      Busca Linear Ordenada
     *      Busca Binária
     */
int main(void){

    return 0;
}

/**
 * Complexidade assintótica: O(N)
 */
int buscaLinear(int *V, int N, int elem){
    int i;
    for(i = 0; i < N; i++){
        if(elem = V[i]){
            // O Elemento foi encontrado
            return i; 
        }
    }
    // O Elemento não foi encontrado!
    return -1;
}

/**
 * Complexidade assintótica: O(N)
 */
int buscaOrdenada(int *V, int N, int elem){
    int i;
    for(i = 0; i < N; i++){
        if(elem == V[i])
            // O elemento foi encontrado
                return i;
        else
            if(elem < V[i])
                // ELemento não existe, para a busca
                return -1;
    }

    return -1; // Elemento não encontrado
}

/*
    Complexidade: O(Log N)
*/
int buscaBinaria(int *V, int N, int elem){

    int i, inicio, meio,final;
    inicio = 0;
    final = N - 1;


    while(inicio <= final){
        meio = (inicio + final) / 2;

        if(elem < V[meio]){
            // Busca na metade da esquerda
            final = meio -1;
        }
        else if(elem > V[meio]){
            // Busca na metade direita
            inicio = meio + 1;
        }
    }

    // ELemento não encontrado
    return -1; 
}

