/*
 * 时间：2018年8月18日11:03:59
 * 目的：输出 EOF 的值
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;

    /* 分别打印输入接收时接收到的 EOF 与 stdio.h 头文件中 宏定义的 EOF 值 */
    printf("提示：windows下输入CTRL+z unix linux mac 下输入 CTRL+d 代表结束输入\n");
    while ((c=getchar()) != EOF)
    {
        printf("输入的字符：%d\n", c);
    }

    printf("接收到的：EOF = %d\n",c);

    printf("打印的宏定义：EOF = %d\n", EOF);

    return 0;
}
