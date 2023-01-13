#include "Queue.h"

int initQueue(ArrayQueue queue) {
    queue->array = malloc(sizeof(E) * 10);
    if (queue->array == NULL) return 1;
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return 0;
}

int offer(ArrayQueue queue, E element) {
    if ((queue->rear + 1) % queue->capacity == queue->front) return 1;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 0;
}

E poll(ArrayQueue queue){
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

int isEmpty(ArrayQueue queue) {
    return queue->rear == queue->front;
}

void printQueue(ArrayQueue queue) {
    printf("<<< ");
    int i = queue->front;   //遍历队列需要从队首开始
    do {
        i = (i + 1) % queue->capacity;   //先向后循环移动
        printf("%d ", queue->array[i]);  //然后打印当前位置上的元素
    } while (i != queue->rear);   //当到达队尾时，结束
    printf("<<<\n");
}

