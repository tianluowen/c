/*
 * 时间: 2020-01-25 21:21
 * 目的: 习题 5.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);     /* 字符串接收和压回的声明 */
void ungetch(int c);
int getfloat(float *pn); /* getint函数：将输入字符串转换为整数存到 pn */

int main(int argc, char *argv[])
{
    float num = 0;

    printf("请输入要转换的浮点型数据: ");
    getfloat(&num);
    printf("转换的结果为: %f\n", num);

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
int getfloat(float *pn)
{
    int c, d, sign;
    float power;

    while (isspace(c = getch()))  /* 跳过空白符 */
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c !='+')
    {
        ungetch(c);               /* 这不是一个数字 */
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
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');           /* 收集整数部分*/
    if (c == '.')
    {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');           /* 收集小数部分 */
        power *= 10;
    }
    *pn *= sign / power;                        /* 最终收集数的大小 */
    if (c == EOF)
        ungetch(c);
    return c;
}

