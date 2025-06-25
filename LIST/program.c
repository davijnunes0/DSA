#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h"

struct aluno createStudent(int matricula, char *name, float n1, float n2,float n3);

int main(){

    Lista *li = cria_lista();
    struct aluno al = createStudent(12345,"Davi",10.0,10.0,10.0);
    struct aluno al2 = createStudent(123456,"Fernando",10.0,20.0,30.0);
    insere_lista_inicio(li,al);
    insere_lista_final(li,al2);
    print_aluno(li);

    struct aluno al3;
    int response = busca_list_pos(li,1,&al3);


}

struct aluno createStudent(int matricula, char* name, float n1, float n2,float n3){

    struct aluno al;
    al.matricula = matricula;
    strcpy(al.nome,name);
    al.n1 = n1;
    al.n2 = n2;
    al.n3 = n3;

    return al;
}