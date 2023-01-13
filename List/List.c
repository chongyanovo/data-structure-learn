#include "List.h"


int initList(ArrayList list) {
    list->capacity = 10;
    list->array = malloc(sizeof(E) * list->capacity);
    if (list->array == NULL) return 1;
    list->size = 0;
    return 0;
}

int insertList(ArrayList list, E element, int index) {
    if (index < 1 || index > list->size + 1) return 1;
    if (list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        E *newArray = realloc(list->array, sizeof(E) * newCapacity);
        if (newArray == NULL) return 1;
        list->array = newArray;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index - 1; i--)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
    list->size++;
    return 0;
}

int deleteList(ArrayList list, int index, E *element) {
    if (index < 1 || index > list->size) return 1;
    *element = list->array[index - 1];
    for (int i = index - 1; i < list->size; i++)
        list->array[i] = list->array[i + 1];
    list->size--;
    return 0;
}

int sizeList(ArrayList list) {
    return list->size;
}

E *getList(ArrayList list, int index) {
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int findList(ArrayList list, E element) {
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == element)
            return i + 1;
    }
    return -1;
}

void printList(ArrayList list) {
    for (int i = 0; i < list->size; ++i)
        printf("%d ", list->array[i]);
    printf("\n");
}
