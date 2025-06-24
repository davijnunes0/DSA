typedef struct item* List;

List* createList();
void freeList(List* list);
int insertStart(List* list, int number);
int  insertEnd(List* list, int number);
void inserInPosition(List* list, int valor, int position);
int printList(List* list);
int size(List* list);
