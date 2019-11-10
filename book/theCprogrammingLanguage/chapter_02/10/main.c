/*
 * 目的：编写函数lower
 * 时间：2018年5月6日14:25:21
 */

#include <stdio.h>

/* lower函数：将字符串s中的大写字母转换为小写字母 */
void lower(char s[]);

int main(int argc, char *argv[])
{
    char s[200];
    printf("请输入要转换的字符串: ");
    scanf("%s", s);

    printf("字符串大写转小写完成: ");
    lower(s);

    printf("%s\n", s);

    return 0;
}

/* lower函数：将字符串s中的大写字母转换为小写字母 */
void lower(char s[])
{
    int i = 0;
    while ('\0' != s[i])
    {
        'A' <= s[i] && s[i] <= 'Z' ? s[i] = s[i] + 'a' - 'A' : NULL;
        ++i;
    }
}
