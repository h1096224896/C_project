#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct Stack
{
    int *base;   
    int *top;    
    int maxsize; 
} SqStack;




bool InitStack(SqStack &s)
{
    s.base = (int *)malloc(MAXSIZE * sizeof(int));
    // S.base = new int[MAXSIZE];  // C++中的动态分配内存
    if (!s.base)
        return false;
    s.top = s.base; // 栈顶指针指向栈底
    s.maxsize = MAXSIZE;
    return true;
}

// 判空
bool StackEmpty(SqStack s)
{
    if (s.base == s.top)
        return true;
    else
        return false;
}

int Stacklength(SqStack s)
{
    return s.top - s.base;
}

bool ClearStack(SqStack s)
{
    if (s.base)
        s.top = s.base;
    return true;
}

bool DestoryStack(SqStack s)
{
    if (s.base)
    {
        // 删除基地址
        delete s.base;
        s.maxsize = 0;
        s.base = s.top = NULL;
    }
    return true;
}

bool Push(SqStack s, int e)
{
    // 先判断栈是否满
    if (s.top - s.base == s.maxsize)
        return false;
    *s.top = e;
    s.top++;
    return true;
}

bool Pop(SqStack s, int &e)
{
    // 判断栈是否为空
    if (s.top == s.base)
        return false;
    s.top--;             // 先把栈顶指针减一
    if (s.top != s.base) // 下溢
        e = *s.top;      // 再把栈顶元素赋值给e
    else
        return false;
    return true;
}

int main()
{

    return 0;
}