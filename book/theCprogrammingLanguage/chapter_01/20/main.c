/*
 * 时间：2018-8-21 10:37:18
 * 目的：编写函数detab，将所有制表符用相应的空格代替
 */

#include <stdio.h>

#define TABINC 8   //tab 的大小

int main(int argc, char *argv[])
{
    int c, nb, pos;

    nb = 0;
    pos = 1;
    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
            nb = TABINC - (pos-1)%TABINC;
            while (nb > 0)
            {
                putchar(' ');
                --nb;
                ++pos;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }

    return 0;
} 
