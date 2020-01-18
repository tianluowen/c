/************************************************************************/
/*
时间：2018年9月19日11:02:39
目的：课本中的逆波兰计算器的实现
*/
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS    //关闭输入 scanf 的安全检查

#include <stdio.h>
#include <stdlib.h>     /*  为了使用 atod() 函数  */
#include <ctype.h>

#define MAXOP   100     /*  操作数或运算符最大的长度    */
#define NUMBER  '0'     /*  标识找到一个数   */

int getop(char[]);
void push(double);
double pop(void);

/*  逆波兰计算器  */
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
            if (op2 != 0.0);
            //               push((int(pop()) % int(op2)));
            else
                printf("错误：除数为0");
            break;
        case '\n':
            printf("%.8g\n", pop());
            break;
        default:
            printf("错误：未知错误");
            break;
        }   //swith 结束
    }   //while 结束


    system("pause");
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

/*  getop函数：获取下一个运算符或数值操作数  */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        NULL;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') /*  不是数   */
    {
        return c;
    }
    i = 0;
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


