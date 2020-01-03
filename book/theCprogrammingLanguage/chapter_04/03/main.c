/************************************************************************/
/* 
    时间：2018年9月13日16:02:17
    目的：给书中的计算机程序增加取模运算，并考虑负数的情况
*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>     /* 为了使用 atod() 函数 */
#include <ctype.h>
#include <math.h>       /* fmod 函数 */

#define MAXOP   100     /* 操作数或运算符最大的长度 */
#define NUMBER  '0'     /* 标识找到一个数 */

int getop(char[]);
void push(double);
double pop(void);

/* 逆波兰计算器 */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("提示: \n");
    printf("输入逆波兰式进行计算 eg: 3 5 * 8 +\n");

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("错误：除数为0");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("错误：除数为0");
            break;
        case '\n':
            printf("该式的计算结果为: %.8g\n", pop());
            break;
        default:
            printf("错误：未知错误");
            break;
        }   //swith 结束
    }   //while 结束

    return 0;
}

#define MAXVAL 100     /*  栈 val 的最大深度   */

int sp = 0;            /*  下一个空闲栈的位置  */
double val[MAXVAL];    /*  值栈   */

/*  push函数：把 f 压入到值栈中   */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("错误：栈满，无法入栈!");
}

/*  pop函数：弹出并返回栈顶的值  */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("错误：栈空，无法取值！");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

/* getop函数: 获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        NULL;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') /* 不是数 */
        return c;
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;                      /* 负数 */
        }
        else
        {
            if (c != EOF)
                ungetch(c);                 /* 减号 */
            return '-';
        }
    }
    if (isdigit(c))   /*  收集整数部分   */
    {
        while (isdigit(s[++i] = c = getch()))
            NULL;
    }
    if (c == '.')    /*   收集小数部分   */
    {
        while (isdigit(s[++i] = c = getch()))
            NULL;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
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
