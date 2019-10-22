/*
 * 时间：2018年8月18日11:40:06
 * 目的：将输入的多个空格使用一个空格代替
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c, index;
    
    printf("提示：windows 下 CTRL + z unix linux mac按下 CTRL + d 结束程序\n");
    printf("请输入测试字符串：\n");
    index = 0;
    /* 后一个字符同前一个字符比较，两个都是空格，就跳过，其他情况都输出前一个字符 */ 
    while ((c=getchar()) != EOF) 
    {
        if (c ==' ')
        {
            if (' ' != index)
            {

                putchar(c);
            }
        }
        else
        {
            putchar(c);
        }
        index = c;
    }
    printf("end\n");

    return 0;
}
