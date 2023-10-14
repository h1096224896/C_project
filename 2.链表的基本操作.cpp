#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 5

// 1.创建链表
typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 指针域
} Node, *LinkList;     // Node为节点名，LinkList为指向结构体Node的指针类型

// 2.初始化链表
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

// 3.插入元素，
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    Node *p; // 指针p指向当前扫描到的节点
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 4.删除元素
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    Node *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    Node *q = p->next;
    if (q == NULL)
        return false;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 5.查找元素
int LocateElem(LinkList L, int e)
{
    int i = 1;
    Node *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0;
    else
        return i;
}

// 6.求表长
int Length(LinkList L)
{
    int i = 0;
    Node *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

// 7.输出链表
void PrintList(LinkList L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 8.清空链表
void ClearList(LinkList &L)
{
    Node *p, *q;
    p = L->next;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

// 9.销毁链表
void DestroyList(LinkList &L)
{
    ClearList(L);
    free(L);
}

// 10.判断链表是否为空
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

// 11.合并两个有序链表
LinkList MergeList(LinkList &La, LinkList &Lb)
{
    Node *pa = La->next;
    Node *pb = Lb->next;
    Node *pc = La;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
    return La;
}

// 12.逆置链表
LinkList ReverseList(LinkList &L)
{
    Node *p = L->next;
    L->next = NULL;
    Node *q;
    while (p != NULL)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return L;
}

// 13.删除最小值
bool DeleteMin(LinkList &L, int &e)
{
    if (L->next == NULL)
        return false;
    Node *p = L->next;
    Node *pre = L;
    Node *minp = p;
    Node *minpre = pre;
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    e = minp->data;
    minpre->next = minp->next;
    free(minp);
    return true;
}

// 14.删除重复元素
void Purge(LinkList &L)
{
    Node *p = L->next;
    Node *q;
    while (p != NULL)
    {
        q = p->next;
        if (q != NULL && q->data == p->data)
        {
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}

int main()
{
    int e, i; // e为元素，i为位置
    // 1.创建链表
    LinkList L = InitList();
    // 2.插入元素
    printf("请输入要插入的元素，以-1结束:\n");
    while (scanf("%d", &e) != EOF && e != -1)
    {
        if (Length(L) >= MAXSIZE) // 判断链表是否已满
        {
            printf("链表已满，无法插入元素\n");
            break;
        }
        ListInsert(L, 1, e); // 头插法
        printf("已在位置1插入元素%d\n", e);
        printf("当前链表为："), PrintList(L), printf("\n");
    }
    // 3.删除元素
    printf("请输入要删除的位置，以-1结束:\n");
    while (scanf("%d", &i) != EOF && i != -1)
    {
        if (ListDelete(L, i, e))
            printf("已删除位置%d上的元素%d\n", i, e);
        else
            printf("删除失败，位置%d不存在元素\n", i);
        printf("当前链表为："), PrintList(L), printf("\n");
    }
    return 0;
}