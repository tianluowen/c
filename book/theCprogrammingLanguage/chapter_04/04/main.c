/************************************************************************/
/*
时间: 2020-01-18 19:16
目的: 增加逆波兰计算器增加 清空栈，交换栈顶两个值，打印栈顶元素，但不取出
*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>     /* 为了使用 atod() 函数 */
#include <ctype.h>
#include <math.h>       /* fmod 函数 */

#define MAXOP   100     /* 操作数或运算符最大的长度 */
#define NUMBER  '0'     /* 标识找到一个数 */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
int is_empty(void);

/*  逆波兰计算器  */
int main(int argc, char *argv[])
{
    int type;
    double result;
    double op1, op2;
    char s[MAXOP];

    printf("输入逆波兰式计算 eg: 3 5 + 4 *\n");

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
                printf("错误：除数为0\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("错误：除数为0\n");
            break;
        case 'c':
            clear();
            printf("\n");
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
            printf("错误：未知错误\n");
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


int getch(void);
void ungetch(int);

/*  getop函数：获取下一个运算符或数值操作数  */
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
        printf("错误：缓冲区已满！\n");
    else
        buf[bufp++] = c;
}

int is_empty(void)
{
    if (sp != 0)
        return 0;
    else
        return 1;
}
