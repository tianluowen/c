/*
 * 时间: 2020-01-31 10:55
 * 目的: 修改第一章的函数
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXLIN      100
#define TABINC      8
#define YES         1
#define NO          0

void settab(int args, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

int main(int argc, char *argv[])
{
    char tab[MAXLIN+1];

    settab(argc, argv, tab);    /* 初始化 */
    entab(tab);                 /* 替换 */

    return 0;
}

void settab(int argc, char *argv[], char *tab)
{
    int i, pos;

    if (argc <= 1)
    {
        for (i = 1; i <= MAXLIN; i++)
        {
            if (i % TABINC == 0)
            {
                tab[i] = YES;
            }
            else
            {
                tab[i] = NO;
            }
        }
    }
    else
    {
        for (i = 1; i < MAXLIN; i++)
        {
            tab[i] = NO;
        }
        while (--argc > 0)
        {
            pos = atoi(*++argv);
        }
        if (pos > 0 && pos <= MAXLIN)
        {
            tab[pos] = YES;
        }
    }
}


int tabpos(int pos, char *tab)
{
    if (pos > MAXLIN)
    {
        return YES;
    }
    else
    {
        return tab[pos];
    }
}


void entab(char *tab)
{
    int c, pos;
    int nb = 0;
    int nt = 0;

    for (pos = 1; (c=getchar()) != EOF; pos++)
    {
        if (c == ' ')
        {
            if (tabpos(pos, tab)  == NO)
            {
                ++nb;
            }
            else
            {
                nb = 0;
                ++nt;
            }
        }
        else
        {
            for (; nt > 0; nt--)
            {
                putchar('\t');
            }
        }
        if (c == '\t')
        {
            nb = 0;
        }
        else
        {
            for (; nb > 0; nb--)
            {
                putchar(' ');
            }
        }

        putchar(c);

        if (c == '\n')
        {
            pos = 0;
        }
        else if (c == '\t')
        {
            while (tabpos(pos, tab) != YES)
            {
                ++pos;
            }
        }
    }
}
