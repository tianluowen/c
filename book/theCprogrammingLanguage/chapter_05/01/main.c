/*
 * 时间: 2020-01-23 22:10
 * 目的: 习题 5.1 
 * 描述: 这道题的基本意思是使得 getint 函数可以识别 +012 一类的数据
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);     /* 字符串接收和压回的声明 */
void ungetch(int c);
int getint(int *pn); /* getint函数：将输入字符串转换为整数存到 pn */

int main(int argc, char *argv[])
{
    int num = 0;

    printf("请输入要转换的整型数字: ");
    getint(&num);
    printf("转换存储的结果为: %d\n", num);

    return 0;
}


#define BUFSIZE 100     

char buf[BUFSIZE];  /*  用于 ungetch 函数的缓冲区*/
int bufp = 0;       /*  buf 中下一个空闲位置  */

int getch(void)     /*  取一个字符，可能是缓冲字符  */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*  把字符压回到输入中*/
{
    if (bufp >= BUFSIZE)
        printf("错误：缓冲区已满！");
    else
        buf[bufp++] = c;
}

/* getint函数：将输入字符串转换为整数存到 pn */
int getint(int *pn)
{
    int c, d, sign;

    while (isspace(c = getch()))  /* 跳过空白符 */
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c !='+')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        d = c;
        if (!isdigit(c = getch()))
        {
            if (c != EOF)
            {
                ungetch(c);
            }
            ungetch(d);
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + c - '0';
    *pn *= sign;
    if (c == EOF)
        ungetch(c);
    return c;
}

