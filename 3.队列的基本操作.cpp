// 队列的初始化
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define InitSize 10 // 定义顺序表的初始长度

#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(EXIT_FAILURE);
    Q.front->next = NULL;
}

int main(int argc, char const *argv[])
{
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}
