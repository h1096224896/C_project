#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElemType; // 栈中元素类型

// 顺序栈定义
typedef struct
{
    ElemType data[MaxSize]; // 存放栈中元素
    int top;                // 栈顶指针,记录栈顶元素在数组中的下标
} Stack;


// 初始化栈
void InitStack(Stack *S)
{
    S->top = -1;        // 初始化栈顶指针
}

// 判断栈是否为空
bool StackEmpty(Stack *S)
{
    if (S->top == -1)  // 栈为空
        return true;
    else
        return false;
}


// 新元素入栈
bool Push(Stack *S, ElemType x)
{
    if (S->top == MaxSize - 1)  // 栈满
        return false;
    S->top++;                   // 栈顶指针自增，指向新的栈顶元素
    S->data[S->top] = x;        // 把top指针指向的位置赋值为x S.data[++S.top] = x;等价
    return true;                // 入栈成功
}



void testStack()
{
    Stack S;
    InitStack(&S);
    printf("%d\n", S.top);
}

int main()
{
    testStack();
    // 
    return 0;
}