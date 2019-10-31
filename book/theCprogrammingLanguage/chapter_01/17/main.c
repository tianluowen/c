/*
 * 时间：2018年8月21日10:13:59
 * 目的：打印输入长度大于80个字符的所有输入行
 */

#include <stdio.h>

#define MAXLINE 1000                   /*设置的最大接收一行字符的数量*/

int getlin(char line[], int maxline); /*获取一行字符的函数         */

int main(int argc, char *argv[])
{
    int len;                           /*当前行长度                */
    char line[MAXLINE];                /*当前行的输入              */

    while ((len=getlin(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
            printf("%d %s", len, line);
        }
    }

    return 0;
}

/* getlin: 获取一行字符的函数 */
int getlin(char line[], int maxline)
{
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar()) != '\n' && c != EOF; ++i)
    {
        if (i < MAXLINE-2)
        {
            line[j] = c;
            ++j;
        }
    }
    if (c == '\n')
    {
        line[j] = c;
        ++j;
        ++i;
    }
    line[j] = '\0';

    return i;
}
