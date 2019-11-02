/*
 * 时间：2018年8月21日16:58:35
 * 目的：将空格串替换为tab加最少的空格
 * 注意：如果只需要一个空格就能达到下一个制表符表位，将之替换为一个制表符，这有助于特殊情况
 *       课后习题是这么解释的，具体什么特殊情况我也没想到，也没有遇见
 */

#include <stdio.h>

#define TABINC 8  /*设置tab键的长度*/

int main(int argc, char *argv[])
{
    int c, nb, nt, pos;

    nb = 0;      /*空格数量*/
    nt = 0;      /*tab数量*/
    for (pos=1; (c=getchar())!=EOF; ++pos)
    {
        if (c == ' ')
        {
            if (pos%TABINC != 0)
            {
                ++nb;                  /*空格加1*/
            }
            else
            {
                nb = 0;                /*空格归0，tab加1*/
                ++nt;
            }
        }
        else
        {
            for (; nt>0; --nt)        /*输出tab*/
            {
                putchar('\t');
            }
            if (c=='\t')
            {
                nb = 0;
            }
            else
            {
                for (; nb > 0; --nb)
                {
                    putchar(' ');       /*输出空格*/
                }
            }
            putchar(c);
            if (c == '\n')              /*tab移动*/
            {
                pos = 1;
            }
            else if (c == '\t')
            {
                pos = pos + (TABINC - (pos-1)%TABINC) - 1;
            }
        }
    }
    return 0;
}
