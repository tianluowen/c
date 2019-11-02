/*
 * 时间：2018年8月22日10:26:14
 * 目的：删除行末尾的空格和tab
 */

#include <stdio.h>

#define MAXLINE 1000    /* 单行输入最大数量 */ 

int getlin(char line[], int maxline);
int remov(char s[]);

int main(int argc, char *argv[])
{
    char line[MAXLINE];

    while (getlin(line, MAXLINE) > 0)
    {
        if (remov(line) > 0)
        {
            printf("%s", line);
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

int remov(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n')
    {
        ++i;
    }
    --i;
    while (i>=0 && (s[i]==' ' || s[i]=='\t'))
    {
        --i;
    }
    if (i >= 0)
    {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}

