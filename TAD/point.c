#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <math.h>
    
struct point{
    float x;
    float y;
};

// Aloca e retorna um ponto com coordenadas "x" e "y"
Point* createPoint(float x,float y){
    Point* p = (Point*) malloc(sizeof(Point));

    if(p != NULL){
        p->x = x;
        p->y = y;
    }

    return p;
}

// Libera a memória alocada para um ponto
void freePoint(Point* p){
    free(p);
}

// Recupera os valores, por referência, o valor de um ponto.
int accessPoint(Point *p, float* x, float* y){

    if(p == NULL) return 0;

    *x = p->x;
    *y = p->y;

    return 1;
}
// Atribui a um ponto as coordenadas "x" e "y"
int addValuePoint(Point* p, float x, float y){

    if(p == NULL){
        return 0;
    }

    p->x = x;
    p->y=  y;

}

// Colcula a distância entre dois pontos.
float distancePoint(Point *p1, Point *p2){

    if(p1 == NULL || p2 == NULL){
        return 0;
    }

    float dx = p1->x - p2->x;
    float dy = p2->y - p2->y;

    return sqrt(dx * dx + dy * dy);
}