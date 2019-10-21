/*
 * 时间：2018年8月18日11:11:11
 * 目的：统计换行，空格制表符
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    int c, nb, nt, nl;

    nb = 0;
    nt = 0;
    nl = 0;
    /* 提示用户输入结束符，不然程序在死循环 */
    printf("windows 下输入 CTRL+z unix linux mac 下输入 CTRL+d 代表结束输入\n");
    while ((c=getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("\n空格=%d 制表符=%d 换行=%d\n", nb, nt, nl);

    return 0;
}
