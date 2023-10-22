#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LinkStack
{
    int data;
    struct LinkStack *next;
} LinkStack, *LinkStackPtr;

bool InitStack(LinkStack *s)
{
    s = NULL; // 头指针置空
    return true;
}

bool StackEmpty(LinkStack *s)
{
    if (s == NULL)
        return true;
    else
        return false;
}

bool Push(LinkStackPtr &s, int e)
{
    LinkStackPtr p;
    p = (LinkStackPtr)malloc(sizeof(LinkStack));
    // p = new LinkStack;  // C++中 new 代替 malloc
    p->data = e;
    p->next = s; //
    s = p;
    return true;
}

bool Pop(LinkStackPtr &s, int &e)
{
    LinkStackPtr p;
    if (s == NULL)
        return false; //
    e = s->data;
    p = s;       // p记录一下需要删除的节点
    s = s->next; // s指向栈顶,删了就把s指向的下一个元素赋值为栈顶
    free(p);
    return true;
}

bool getTopElem(LinkStackPtr s, int &e)
{
    if (s)
        return e = s->data;
}



int main()
{
    
    return 0;
}