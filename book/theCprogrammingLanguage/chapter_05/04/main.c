/*
 * 时间: 2020-01-27 20:13
 * 目的: 编写函数 strend(s, t) 如果字符串 s 末尾是 字符串 t，则返回 1，否则返 0
 */

#include <stdio.h>
#include <stdlib.h>

/* strend函数：检测字符串s的末尾是不是字符串t，是的话返回1，否则返回0 */
int strend(const char *s, const char *t);

int main(int argc, char *argv[])
{
    char s[1024] = {'\0'};
    char t[1024] = {'\0'};

    printf("请输入要检测的字符串 s: ");
    scanf("%s", s);
    printf("请输入要判断 s 末尾存在的字符串 t: ");
    scanf("%s", t);

    if (strend(s, t))
        printf("字符串 %s 的末尾 是 字符串 %s\n", s, t);
    else
        printf("字符串 %s 的末尾 不是 字符串 %s\n", s, t);

    return 0;
}

/* strend函数：检测字符串s的末尾是不是字符串t，是的话返回1，否则返回0 */
int strend(const char *s, const char *t)
{
    const char *bs = s;
    const char *bt = t;

    while (*bt)     /* 找到字符串末尾 */
        bt++;
    while (*bs)     /* 找到字符串末尾 */
        bs++;
    for (; *s == *t; s--, t--)
    {
        if (t == bt || s == bs)
            break;                  /* 字符串开始 */
    }
    if (*s == *bt && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}
