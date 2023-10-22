#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 顺序栈的定义
#define MaxSize 100
typedef struct
{
    int *top;
    int *base;
    int stacksize; // 栈的最大容量
} SqStack;

// 初始化栈
bool InitStack(SqStack &s)
{
    // s.base = (int *)malloc(sizeof(int) * MaxSize);
    s.base = new int[MaxSize];
    if (!s.base)
        return false;
    s.top = s.base;
    s.stacksize = MaxSize;
    return true;
}

// 判断顺序栈是否为空
bool StackEmpty(SqStack s)
{
    if (s.top == s.base)
        return true;
    else
        return false;
}

// 求顺序栈的长度
int StackLength(SqStack s)
{
    return s.top - s.base;
}

// 销毁顺序栈
bool DestroyStack(SqStack &s)
{
    if (s.base)
    {
        delete s.base;
        s.stacksize = 0;
        s.base = s.top = NULL;
    }
    return true;
}

// 清空顺序栈
bool clearStack(SqStack s)
{
    if (s.base)
        s.top = s.base;
    return true;
}

// 顺序栈的进栈
bool Push(SqStack &s, int e)
{
    if (s.top - s.base == s.stacksize)
        return false;

    *s.top = e;
    s.top++;
    return true;
}

// 顺序栈的出栈
bool Pop(SqStack &s, int &e)
{
    if (s.top == s.base) // 下溢
        return false;
    --s.top;
    e = *s.top;
    return true;
}

// 读栈顶元素
bool GetTop(SqStack *s, int &e)
{
    if (s->top == s->base)
        return false;
    e = *(s->top - 1);
    return true;
}

// 将十进制数转换为二进制数
void conversion(int n)
{
    SqStack s;
    InitStack(s);
    while (n)
    {
        Push(s, n % 2);
        n /= 2;
    }
    while (!StackEmpty(s))
    {
        int e;
        Pop(s, e);
        printf("%d", e);
    }
}

int main()
{
    // 1. 创建栈
    SqStack s;
    // 2. 初始化栈
    InitStack(s);
    // 3. 进栈
    printf("请输入要进栈的元素，以-1结束:\n");
    while (1)
    {
        int e;
        scanf("%d", &e);
        if (e == -1)
            break;
        Push(s, e);
    }
    // 打印栈内元素
    printf("栈内元素为:\n");
    for (int i = 0; i < StackLength(s); i++)
        printf("%d ", *(s.base + i));

    // 栈内元素依次输出，同时转为二进制数
    printf("\n栈内元素依次出栈，转为二进制数:\n");
    while (!StackEmpty(s))
    {
        int e;
        Pop(s, e);
        printf("%d 对应的二进制数为：", e), conversion(e), printf("\n");
    }

    return 0;
}