/*
* 时间: 2020-01-22 14:57
* 目的: 使用 printd 函数递归思想编写 itoa 函数，通过递归调用把整数转换为字符串
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* itoa函数：通过递归调用把整数转换为字符串*/
void itoaa_self(int n, char s[]);

int main(int argc, char *argv[])
{
    int num = 0;
    char s[100];

    printf("请输入要转化的整数: ");
    scanf("%d", &num);

    itoaa_self(num, s);

    printf("经 itoaa_self 函数转化后的整数字符串输出为: %s\n", s);

    return 0;
}

/* itoa函数：通过递归调用把整数转换为字符串*/
void itoaa_self(int n, char s[])
{
    static int i;
    if (n / 10)
    {
        itoaa_self(n / 10, s);
    }
    else
    {
        i = 0;
        if (n < 0)
        {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

