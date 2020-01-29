/*
 * 时间: 2020-01-29 16:25
 * 目的: 重新编写 readline 函数
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 10     /* MAXLINE 行的最大长度 */
#define MAXSTOR 128    /* 空格 */

/* readlines函数：*/
int readlines(char *lineptr[], char *linestor, int maxlines);
int getline_self(char *s, int lim);

int main(int argc, char *argv[])
{
    char str[MAXLINE][MAXSTOR];
    char t[MAXSTOR];

    readlines((char **)str, t, MAXLINE);
    
    return 0;
}

/* readlines函数： */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLINE];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while ((len = getline_self(line, MAXLINE) > 0))
    if (nlines >= maxlines || p+len > linestop)
        return -1;
    else
    {
        line[len-1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
    }

    return nlines;
}

/* getline_self函数：读取一行字符串，返回长度 */
int getline_self(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 &&(c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    /* 决定计算不计算输入的回车符号 */
    /* if (c == '\n') */
    /*     *s++ = c; */
    *s = '\0';
    return s - t;
}
