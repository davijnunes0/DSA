/**
 * TAD (Tipo abstrato de dados)
 */

// Aliases para nossa lista
typedef struct element* List;

// Função que cria uma lista.
List* createList();
// Função que libera os nó de uma lista.
int freeList(List* li);
// Função que adiciona o nó no início da lista.
int addInStart(List* li,int data);
// Função que adiciona o nó no fim da lista.
int addInEnd(List* li, int data);
// Função que insere em uma posição específica
int addInPosition(List* li, int data, int pos);
// Função que remove no começo da lista.
int removeInStart(List* li);
// Função que remove um elemento no final da lista;
int removeInEnd(List* li);
// Função que remove um elemento específico.
int removeElement(List* li, int data);
// Função que busca um elemento.
int searchElement(List* li, int data);
// Função que imprime a lista.
int printList(List* li);
