#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct List {
    E * array;
    int capacity;
    int size;
};

typedef struct List *ArrayList;

int initList(ArrayList list);

int insertList(ArrayList list,E element,int index);

int deleteList(ArrayList list,int index,E *element);

int sizeList(ArrayList list);

E* getList(ArrayList list,int index);

int findList(ArrayList list,E element);

void printList(ArrayList list);


