/*
 * 时间: 2020-01-31 10:03
 * 目的: 编写函数expr计算逆波兰表达式的值
 * 描述: 运行程序时加入参数 参数为 逆波兰表达式
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>           /* for atof() */

#define     MAXOP   100     /* 最大缓存长度 */
#define     NUMBER  '0'     /* 数字 */
#define     ERROR_NUMBER 1  /* 错误类型1，输入的数字不合法 */

double val[MAXOP] = {0};
int sp = 0;

/*  pop函数：弹出并返回栈顶的值  */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("错误：栈空，无法取值!");
        return 0.0;
    }
}

/*  push函数：把 f 压入到值栈中   */
void push(double f)
{
    if (sp < MAXOP)
        val[sp++] = f;
    else
        printf("错误：栈满，无法入栈!");
}

/* getop函数：判断字符串 c 是不是数字 */
int getop(char c)
{
    if (isdigit(c))
    {
        return NUMBER;
    }
    else
    {
        return c;
    }
}

int main(int argc, char *argv[])
{
    // char s[MAXOP] ={ '\0' };
    double op2 = 0;

    while (--argc > 0)
    {
        //strcpy(s, *++argv);
        switch (getop(**++argv))
        {
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("ERROR:输入参数有误!\n");
                argc = 1;
            }
            break;
        default:
            printf("ERROR:输入参数无法识别!\n");
            argc = 1;
            break;
        }
    }
    
    printf("%.8g\n", pop());

    return EXIT_SUCCESS;
}

