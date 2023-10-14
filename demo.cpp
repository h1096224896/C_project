#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LNode
{
    int *data;
    struct LNode *next;
} LNode, *LinkList;

// 单链表的初始化
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}



int main()
{
    LNode *L;
    InitList(L);

    return 0;
}