#include "List.h"

int main() {
    struct List list;
    if (initList(&list)) {
        printf("顺序表初始化失败...");
    }

    insertList(&list,666,1);
    printList(&list);
    insertList(&list,777,1);
    printList(&list);
    insertList(&list,888,2);
    printList(&list);
    printf("%d", *getList(&list,findList(&list,888)));
//    int elem;
//    deleteList(&List,3,&elem);
//    printList(&List);
//    printf("%d",elem);
//    printf("\n");
//    printf("%d", *getList(&List,2));
}