#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 顺序栈的实现
#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

// 销毁栈
void DestroyStack(SqStack *&s)
{
    free(s);
}

// 判断栈是否为空
bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

// 进栈
bool Push(SqStack *&s, int e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

// 出栈
bool Pop(SqStack *&s, int &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

// 读栈顶元素
bool GetTop(SqStack *s, int &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}


// 将十进制数转换为二进制数
void conversion(int n)
{
    SqStack *s;
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
    SqStack *s;
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
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }

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