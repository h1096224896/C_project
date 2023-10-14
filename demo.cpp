#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void bubble_sort(int *arr, int length){
    int t;
    int a;
}

int main()
{
    // bubble sort
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
        printf("第%d次排序结果：", i + 1);
        for (j = 0; j < 10; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    return 0;
}