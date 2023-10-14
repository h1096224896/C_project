#include <iostream>
#include <cstdio>
using namespace std;

#define InitSize 8
#define MaxSize 8

typedef int ElemType; // 顺序表中元素类型

// 定义顺序表
typedef struct
{
    ElemType *data; // 指示动态分配数组的指针
    int Maxsize;    // 顺序表的最大容量
    int length;     // 顺序表的当前长度
} SqList;

// 初始化顺序表
void InitList(SqList &L) // 初始化顺序表
{
    L.data = (int *)malloc(InitSize * sizeof(int)); // 为顺序表分配内存空间
    L.length = 0;                                   // 顺序表的长度为0
    L.Maxsize = InitSize;                           // 顺序表的最大长度为10
}
// 创建顺序表
void WriteList(SqList &L)
{
    printf("请输入你要创建的顺序表的长度:");
    scanf("%d", &L.length);
    printf("请输入%d个你要放入顺序表里的元素:", L.length);
    for (int i = 0; i < L.length; i++)
        scanf("%d", &L.data[i]);
}

void IncreaseSize(SqList &L) // 增加顺序表的长度
{
    int len;
    int *p = L.data;
    printf("请输入你要增加的顺序表的长度:");
    scanf("%d", &len);
    L.data = (int *)malloc((L.Maxsize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];
    L.Maxsize = L.Maxsize + len;
    free(p);
}

bool ListInsret(SqList &L) // 插入元素
{
    int i, e;
    printf("请输入要插入顺序表的元素和元素位置:");
    scanf("%d %d", &e, &i);
    if (i < 1 || i > L.length + 1)
    {
        printf("插入失败,位置不合法，或者已经超出最大范围\n");
        return false;
    }
    if (L.length > L.Maxsize) // 如果顺序表的长度大于顺序表的最大长度，就增加顺序表的长度
        IncreaseSize(L);      // 增加顺序表的长度
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 将第i个元素及其后面的元素后移
    }
    L.data[i - 1] = e; // 将元素e放在第i个位置
    L.length++;        // 顺序表的长度加1
    printf("插入的元素是%d,插入的位置是%d\n", e, i);
    return true;
}

bool ListDelete(SqList &L) // 删除操作
{
    int i, e;
    printf("请输入要删除的元素位置:");
    scanf("%d", &i);
    if (i < 1 || i > L.length + 1)
    {
        printf("删除失败,位置不合法，或者已经超出最大范围\n");
        return false;
    }
    if (!L.data)
    {
        printf("顺序表不存在\n");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j <= L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("成功把第%d上的元素%d删除\n",i,e);
    return true;
}

bool GetElem(SqList &L) // 按位查找
{
    int i;
    printf("你要找第几个元素:");
    scanf("%d", &i);
    if (i < 1 || i > L.length + 1)
    {
        printf("查找失败\n");
        return false;
    }
    printf("第%d个元素是%d\n", i, L.data[i - 1]);
    return true;
}

void LocateElem(SqList &L) // 按值查找
{
    int e;
    int k = 1;
    printf("输入你要查找的元素值:");
    scanf("%d", &e);
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
        {
            printf("找到了,是第%d个元素\n", i + 1);
            k = 0;
            break;
        }
    if (k)
        printf("找不到元素%d\n", e);
}

bool PrintList(SqList &L) // 打印顺序表
{
    if (!L.data)
        return false;
    printf("顺序表里的元素有:");
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    return true;
}

void DestroyList(SqList &L) // 销毁顺序表
{
    char a;
    getchar();
    printf("是否销毁顺序表(Y/N):");
    scanf("%c", &a); // 清除缓冲区的回车
    if (a == 'Y')
    {
        L.length = 0;
        L.Maxsize = 0;
        free(L.data);
        printf("顺序表已销毁\n");
    }
}

// 求表长
int Length(SqList &L) // 求表长
{
    if (L.length == 0) // 空表
        return 0;
    return L.length;
}

int main()
{
    // 功能选择。包括1.创建顺序表 2.添加新元素 3。删除元素 4.按位查找 5.按值查找 6.打印顺序表 7.销毁顺序表 8.求表长 9.退出
    SqList L;  // 定义顺序表
    int key;
    InitList(L);
    printf("--------欢迎使用顺序表---------\n");
    // printf("\t1.创建顺序表 \n\t2.添加新元素 \n\t3.删除元素 \n\t4.按位查找 \n\t5.按值查找 \n\t6.打印顺序表 \n\t7.销毁顺序表 \n\t8.求表长 \n\t9.退出\n");
    while (1)
    {
        printf("\n=========================请选择你要进行的操作==========================\n");
        printf("1.创建 2.插入 3.删除 4.打印 5.退出\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            WriteList(L); // 创建顺序表
            break;
        case 2:
            ListInsret(L); // 插入元素
            break;
        case 3:
            ListDelete(L); // 删除元素
            break;
        case 4:
            PrintList(L);  // 打印顺序表
            break;
        case 5: // 退出
            exit(0);
        default: // 输入错误
            printf("输入错误，请重新输入\n");
            break;
        }
    }
    return 0;
}

// int main()
// {
//     SqList L;     // 定义顺序表
//     InitList(L);  // 初始化
//     WriteList(L); // 创建
//     for (int i = 0; i < 4; i++)
//     {
//         ListInsret(L); // 插入4个数
//         PrintList(L);
//     }
//     for (int i = 0; i < 3; i++)
//         ListDelete(L); // 删除3个数
//     return 0;
// }
