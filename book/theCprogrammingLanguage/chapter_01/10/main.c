/*
 * 时间：2018年8月18日11:53:14
 * 目的：将制表符换行符换成\n \t
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;

    printf("提示：windows 下使用 CTRL + z  unix linux mac 下使用 CTRL + d 结束程序\n");
    printf("请输入要测试的字符串\n");
    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if ('\b' == c)
        {
            printf("\\b");
        }
        else if ('\\' == c)
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}
