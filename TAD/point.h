typedef struct point Point;

// Cria um novo ponto
Point* createPoint(float x, float y);
// Libera um ponto
void freePoint(Point *p);
//  Acessa os valores "x" e "y" de um ponto
int accessPoint(Point *p, float* x, float* y);
// Atribui os valores "x" e "y" de um ponto
int addValuePoint(Point *p, float x, float y);
// Calcula a distância entre dois pontos;
float distancePoint(Point *p1, Point *p2);
