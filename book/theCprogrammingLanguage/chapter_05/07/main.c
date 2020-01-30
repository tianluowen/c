/*
 * 时间: 2020-01-29 16:25
 * 目的: 重新编写 readline 函数
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 128     /* MAXLINE 行的最大长度 */
#define MAXSTOR 1280    /* 空格 */

/* readlines函数：*/
int readlines(char *lineptr[], char *linestor, int maxlines);
int getline_self(char *s, int lim);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[])
{
    char *str[MAXLINE];
    char t[MAXSTOR];
    int i = 0;
    int nline = 0;

    printf("请输入测试内容:\n");
    nline = readlines(str, t, (int)(MAXSTOR / MAXLINE));
    printf("\n");
    printf("总共输入 %d 行字符\n", nline);

    printf("这是输入内容: \n");
    writelines(str, nline);
    
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
    while ((len = getline_self(line, MAXLINE)) > 0)
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
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* writelines函数: 输入行 */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

