/*
 * 时间：2018年8月18日17:07:17
 * 目的：打印单词长度的直方图
 */

#include <stdio.h>

#define MAXHIST 15       /*输入行数最大长度*/
#define MAXWORD 11       /*输入单词最大长度*/
#define IN      1        /*输入一个单词    */
#define OUT     0        /*输出一个单词    */

int main(int argc, char *argv[])
{
    int c, i, j, nc, state;
    int maxvalue;
    int ovflow;
    int wl[MAXHIST];
    state = OUT;
    nc = 0;
    ovflow = 0;
    for (i=0; i<MAXWORD; ++i)
    {
        wl[i] = 0;
    }
    
    printf("提示：windows 下使用 CTRL + z  unix linux mac 下使用 CTRL + d 结束输入\n");
    printf("请输入要测试的字符串\n");

    /* 以空格符 换行符 制表符 为分隔，统计所有输入单词的长度 
     * 将所有长度大于 10 的单词在一起统计 */
    while ((c=getchar()) != EOF)
    {
        if (c==' ' || c=='\n' || c=='\t')
        {
            state = OUT;
            if (nc > 0)
            {
                if (nc < MAXWORD)
                {
                    ++wl[nc];
                }
                else
                {
                    ++ovflow;
                }
            }
            nc = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            nc = 1;
        }
        else
        {
            ++nc;
        }
    }

    /* 根据单词最多的数 决定了 打印结果的行数  */
    maxvalue = 0;
    for (i=1; i<MAXWORD; ++i)
    {
        if (wl[i] > maxvalue)
        {
            maxvalue = wl[i];
        }
    }

    /* 打印图形，根据单词数与打印行的关系确定输出 * 还是空白符 */
    for (i = maxvalue; i>0; --i)
    {
        putchar(' ');
        for (j=1; j<MAXWORD; ++j)
        {
            if (wl[j] < i)
            {
                printf("     ");
            }
            else
            {
                printf("  *  ");
            }
            --maxvalue;
        }
        printf("\n");
    }

    /* 打印单词字符数与单词数 */
    for (i=1; i<MAXWORD; ++i)
    {
        printf("%4d ", i);
    }
    putchar('\n');
    for (i=1; i<MAXWORD; ++i)
    {
        printf("%4d ", wl[i]);
    }
    putchar('\n');
    if (ovflow > 0)
    {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }

    return 0;
}
