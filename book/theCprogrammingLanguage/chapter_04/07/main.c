/*
* 时间: 2020-01-18 21:48
* 目的: 能把字符串压缩到输入中
*/

#define _CRT_SECURE_NO_WARNINGS    //关闭输入 scanf 的安全检查

#include <stdio.h>      /* 标准输入输出函数 */
#include <stdlib.h>     /* 为了使用 atod() 函数 */
#include <ctype.h>      /* atof 函数，字符串转换为实数的函数*/
#include <math.h>       /* fmod 函数 */
#include <string.h>     /* 字符串判断相等函数 */

#define MAXOP   100     /* 操作数或运算符最大的长度 */
#define NUMBER  '0'     /* 标识找到一个数 */
#define NAME    'n'     /* 标识找到一个函数名 */

int getop(char[]);  /* 获取输入的函数 */
void push(double);  /* 压栈 */
double pop(void);   /* 出栈 */
void clear(void);   /* 清空栈 */
void mathfnc(char[]);   /* 处理数学函数 */
int is_empty(void);

/*  逆波兰计算器  */
int main(void)
{
    int i, type, var = 0;
    double result;
    double op1, op2, v;
    char s[MAXOP];
    double variable[26];

    printf("输入逆波兰式计算 eg: 3 5 + 4 *\n");

    for (i = 0; i < 26; i++)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
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
                printf("错误：除数为0\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("错误：除数为0\n");
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("错误：变量名不存在!\n");
            break;
        case 'c':
            clear();
            break;
        case '?':
            op2 = pop();
            printf("%.8g\n", op2);
            push(op2);
        case 's':
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case '\n':
            if (is_empty())
            {
                printf("输入逆波兰式计算 eg: 3 5 + 4 *\n");
                break;
            }

            /* 取出值来判断，如果这个值有问题，则重新放进去, 不影响栈内的原有的数据 */
            result = pop();
            if (!is_empty() && result != 0)
            {
                printf("输入逆波兰式有误\n");
                printf("请输入清栈指令后重试: c\n");
                push(result);
            }
            else if (result != 0)
            {
                printf("%.8g\n\n", result);
                if (is_empty())
                {
                    printf("输入逆波兰式计算 eg: 3 5 + 4 *\n");
                }
                else
                {
                    printf("逆波兰式输入不完整，请继续输入: ");
                }
            }
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(variable[type - 'A']);
            else if (type == 'v')
                push(v);
            else
                printf("错误：未知错误\n");
            break;
        }   //swith 结束
        var = type;
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
        printf("错误：栈满，无法入栈!\n");
}

/*  pop函数：弹出并返回栈顶的值  */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("错误：栈空，无法取值！\n");
        return 0.0;
    }
}

/* clear函数：清空栈 */
void clear(void)
{
    sp = 0;
}


int getch(void);    /* 获取一个字符 */
void ungetch(int);  /* 字符压回到输入 */
void ungets(char s[]); /* 字符压回到输入 */

/*  getop函数：获取下一个运算符或数值操作数  */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        NULL;
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {
        while (islower(s[++i] = c = getch()))
            NULL;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }
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
        printf("错误：缓冲区已满！\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) /* 字符压回到输入 */
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}


/* 处理数学函数 */
void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0)
    {
        push(cos(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
    {
        printf("错误：输入错误，没有定义的操作！\n");
    }
}

int is_empty(void)
{
    if (sp != 0)
        return 0;
    else
        return 1;
}
