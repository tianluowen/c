/*
 * 时间：2018年9月13日10:43:55
 * 目的：编写函数itob（n, s, b）将n转换为任意b进制的数，存在s中
 */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b, int w);  //itob 函数：将n转换为任意b进制的数，存在s中

int main(int argc, char *argv[])
{
    int num, b, w;            //定义变量 num 存储要转换的数，定义变量 b 存储要转换的进制
    char s[100];           //定义字符串 s，存储转换后数据的结果

    printf("请输入要转换的数：");
    scanf("%d", &num);
    printf("请输入要转换的进制：");
    scanf("%d", &b);
    printf("请输入最短宽度要求：");
    scanf("%d", &w);

    itob(num, s, b, w);

    printf("转换结果为: %s\n", s);

    return 0;
}

//itob 函数：将n转换为任意b进制的数，存在s中
void itob(int n, char s[], int b, int w)
{
    int sign;    //定义变量存储 n 后面可以判断正负
    int i, j;    //用于字符串下标
    char c;      //用于字符串颠倒的时候，临时存储

    sign = n;
    if (n<0)
    {
        n = -n;
    }
    i = 0;
    while (n > 0)    //转换进制
    {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
        n = n / b;
    }
    if (sign < 0)
    {
        s[i++] = '-';
    }

    while (i < w)      //不满足宽度的时候，空白填充
    {
        s[i++] = ' ';
    }
    s[i] = '\0';       //添加字符串 结束符

    j = 0;
    i = i - 1;
    while (j < i)       //颠倒字符顺序
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        --i;
        ++j;
    }
}
