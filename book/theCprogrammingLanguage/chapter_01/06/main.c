/*
 * 时间：2018年8月18日11:03:59
 * 目的：验证表达式getchar() ！= EOF的取值是0还是1
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;

    /* 分别打印输入接收时接收到的 EOF 与 stdio.h 头文件中 宏定义的 EOF 值 */
    printf("提示：windows下输入CTRL+z unix linux mac 下输入 CTRL+d 代表结束输入\n");
    while (n = (getchar() != EOF))
    {
        printf("n = (getchar() != EOF) 的值为：%d\n", n);
    }

    return 0;
}
