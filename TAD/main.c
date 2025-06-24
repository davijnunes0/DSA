#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){

    float d;
    Point *p, *q;
    // Point r; // Erro;
    p = createPoint(10,21);
    q = createPoint(7,25);
    // q->x = 2; erro;
    d = distancePoint(p,q);
    printf("Distancia entre pontos: %f\n",d);
    freePoint(p);
    freePoint(q);

    return 0;
}