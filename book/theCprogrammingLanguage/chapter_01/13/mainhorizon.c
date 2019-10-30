/*
 * 时间：2019年10月29日21:57:18
 * 目的：打印输入单词统计数的水平方向直方图
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXHIST 15       /*输入行数最大长度*/
#define MAXWORD 11       /*输入单词最大长度*/
#define IN      1        /*输入一个单词    */
#define OUT     0        /*输出一个单词    */

int main(void)
{

    int c, i, j, nc, state;
    int len;            /* 需要打印的水平长度 */
    int maxvalue;       /* wl[] 的最大值 */
    int ovflow;         /* 单词长度 > MAXWORD 的个数 */
    int wl[MAXHIST];    /* 单词长度计数 */

    /* 初始化数据 */
    state = OUT;
    nc = 0;             /* 一个单词的长度统计变量 */
    ovflow = 0;          
    for (i=0; i<MAXWORD; ++i)
    {

        wl[i] = 0;
    }

    printf("提示：windows 下使用 CTRL + z  unix linux mac 下使用 CTRL + d 结束输入\n");
    printf("请输入要测试的字符串\n");

    /* 统计数字单词的个数和长度 */
    state = OUT;
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
    maxvalue = 0;
    for (i=1; i<MAXWORD; ++i)
    {

        if (wl[i] > maxvalue)
        {

            maxvalue = wl[i];
        }
    }

    /* 打印水平方向直方图 */
    for (i = 1; i < MAXWORD; ++i)
    {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXWORD / maxvalue) <= 0)
            {
                len = 1;
            }
        }
        else 
        {
            len = 0;
        }
        while (len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovflow > 0)
    {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }

    return 0;
}
