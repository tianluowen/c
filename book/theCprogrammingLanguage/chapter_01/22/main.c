/*
 * 时间：2018年8月21日17:35:35
 * 目的：将长行拆成2行输出
 */

#include <stdio.h>

#define MAXCOL 10   /*输入的最大长度*/
#define TABINC 8    /*tab键的大小  */

char line[MAXCOL];  /*存储输入*/

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

int main(int argc, char *argv[])
{
    int c, pos;
     
    pos = 0;                            //初始化pos位置
    while ((c=getchar())!=EOF)
    {
        line[pos] = c;
        if ('\t' == c)
        {
            pos = exptab(pos);           //制表符pos的变化
        }
        else if ('\n' == c)
        {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL)
        {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

/* exptab: 输入为tab 改变pos的位置*/
int exptab(int pos)
{
    line[pos] = ' ';
    for (++pos; pos<MAXCOL && pos%TABINC!=0; ++pos)
    {
        line[pos] = ' ';
    }
    if (pos < MAXCOL)
    {
        return pos;
    }
    else
    {
        printl(pos);
        return 0;
    }
}

/* findblank：找出非空格的位置*/
int findblank(int pos)
{
    while (pos > 0 && line[pos]!=' ')
    {
        --pos;
    }
    if (pos < MAXCOL)
    {
        return pos;
    }
    else
    {
        printl(pos);
        return 0;
    }
}

/* newpos:新的位置*/    
int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
    {
        return 0;
    }
    else
    {
        i = 0;
        for (j=pos; j<MAXCOL; ++j)
        {
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}

/* printl：输出line字符串*/
void printl(int pos)
{
    int i;
    for (i=0; i<pos; i++)
    {
        putchar(line[i]);
    }
    if (pos > 0)
    {
        putchar('\n');
    }
}   
