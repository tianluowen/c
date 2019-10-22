/*
 * 时间：2018年8月18日16:58:28
 * 目的：每行一个单词输出
 */

#include<stdio.h>

int main(int argc, char *argv[])
{
    char c;
    int other = 0;
    int num = 0;

    printf("请输入要测试的内容\n");
    while ((c = getchar()) != EOF)
    {
        if (('A' <= c&&c <= 'Z') || ('a' <= c&&c <= 'z'))
        {
            other = 0;
            putchar(c);
        }
        else
        {
            if (other == 0)
            {
                other = 1;
                printf("\n");
            }
        }
    }

    return 0;
}
