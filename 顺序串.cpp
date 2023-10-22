#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
typedef struct SqString
{
    char ch[MAXLEN + 1]; // 串的内容, 0号单元存放串的长度
    int length;
} SqString; // 顺序串

// 顺序串的初始化
bool StrAssign(SqString &s, char cstr[]) {
    int i = 0;
    s.ch[0] = 0;  // 首元素不用
    int len = strlen(cstr);
    if (len > MAXLEN) {
        printf("Error: string too long!\n");
        return false;
    }
    for (i = 1; i <= len; i++) {
        s.ch[i] = cstr[i - 1];
    }
    s.ch[i] = '\0'; // 串的结束符
    s.length = len;
    return true;
}

int index_BF(SqString s, SqString t)
{
    int i = 1, j = 1;
    while (i <= s.length && j <= t.length)
    {
        if (s.ch[i] == t.ch[j])
            ++i, ++j;   // 主串和字串依次比较
        else
        {
            i = i - j + 2;
            j = 1;    
        }   
    }
    if (j > t.length)
        return i - t.length;
    else
        return 0;
}

int main()
{
    SqString s, t;
    char str1[] = "hanjiahui";
    char str2[] = "jia";
    StrAssign(s, str1);
    StrAssign(t, str2);
    printf("s: %s || s.length:%d\n", s.ch+1, s.length);
    printf("t: %s || t.length:%d\n", t.ch+1, t.length);
    printf("%d\n", index_BF(s, t));
    return 0;
}