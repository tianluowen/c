/*
* 时间: 2020-01-22 15:03
* 目的: 使用递归编写字符串转置函数 reserve
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* reversee函数：颠倒字符串 s 中的内容*/
void reversee(char s[]);

int main(int argc, char *argv[])
{
    char s[100];
    printf("请输入要转换的字符串: ");
    scanf("%s", s);
    reversee(s);
    printf("转换结果为: %s\n", s);

    return 0;
}

/* reversee函数：颠倒字符串 s 中的内容*/
void reversee(char s[])
{
    void reverseee(char s[], int i, int len);
    
    reverseee(s, 0, strlen(s) - 1);
}

void reverseee(char s[], int i, int len)
{
    int c;

    if (i < len)
    {
        c = s[len];
        s[len] = s[i];
        s[i] = c;
        reverseee(s, ++i, --len);
    }
}
