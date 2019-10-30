/*
 * 时间：2018年8月20日20:17:27
 * 目的：可以打印任意长度的行输入
 */

#include <stdio.h>

#define MAXLINE 1000                   /*设置的最大接收一行字符的数量*/

int getlin(char line[], int maxline); /*获取一行字符的函数         */
void copy(char to[], char from[]);     /*从from复制到to            */

int main(int argc, char *argv[])
{
    int len;                           /*当前行长度                */
    int max;                           /*zui                      */
    char line[MAXLINE];                /*当前行的输入              */
    char longgest[MAXLINE];            /*太长的行保存在这里         */

    max = 0;
    while ((len=getlin(line, MAXLINE)) > 1)
    {
        printf("%d %s", len, line);
        if (len > max)
        {
            max = len;
            copy(longgest, line);
        }
    }
    if (max > 1)
    {
        printf("%s", longgest);
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
    if (c = '\n')
    {
        line[j] = c;
        ++j;
    }
    line[j] = '\0';

    return j;
}

/* copy: from复制到to */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i]=from[i]) != '\0')
    {
        ++i;
    }
}
