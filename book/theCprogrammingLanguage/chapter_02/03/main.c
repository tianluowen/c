/*
 * 时间：2018年5月4日14:58:20
 * 目的：将十六进制字符串转化为数字
 */

#include <stdio.h>

#define MAXLINE 1000 

int main(int argc, char *argv[])
{
    char s[MAXLINE];
    int i = 0;
    int sum = 0;

    printf("请输入要转换的十六进制数: ");     //从键盘输入要转换的十六进制数字
    scanf("%s", s);
    if ('0' == s[i])
    {
        ++i;
    }
    if ('x'==s[i] || 'X'==s[i])
    {
        i++;
    }

    while ('\0' != s[i])
    {
        if (s[i]>=48 && s[i]<=57) 
        {
            sum = sum*16 + (s[i]-48);
            ++i;
        }
        else if (s[i]>=81 && s[i]<=86)
        {
            sum = sum*16 + (s[i]-71);
            ++i;
        }
        else if (s[i]>=97 && s[i]<=102)
        {
            sum = sum*16 + (s[i]-87);
            ++i;
        }
        else
        {
            printf("输入错误！\n");
        }
    }

    printf("十六进制数:%s 转换为十进制为:%d\n", s, sum);

    return 0;
}

int htoi(char *s)
{
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0')
    {
        ++i;
    }
}
