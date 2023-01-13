#include "Queue.h"

int main(){
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offer(&queue, i * 100);
    }
    printQueue(&queue);
    printf("%d\n",poll(&queue));
    printf("%d\n",poll(&queue));
    printf("%d\n",poll(&queue));
    printQueue(&queue);
}