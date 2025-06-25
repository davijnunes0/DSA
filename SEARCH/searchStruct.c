#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

int main(void){

}

int buscaLinearMatricula(struct aluno *V, int N, int elem){

    int i;
    for(i = 0; i<N; i++){
        if(elem == V[i].matricula){
            // Retorna a posição do aluno com a determinada matricula
            return i;
        }
    }

    // Elemento não encontrado
    return -1;
}

int buscaLinearNome(struct aluno *V, int N, char* elem){
    int i;
    for(i = 0; i < N;i++){
        if(strcmp(elem,V[i].nome) == 0){
            // Retorna a posição daquele aluno específicado.
            return i;
        }
    }

    // Elemento não foi encontrado
    return -1;
}