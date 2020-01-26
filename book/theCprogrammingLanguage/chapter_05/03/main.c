/*
 * 时间: 2020-01-26 19:45
 * 目的: 用指针方式实现 strcat 函数
 */

#include <stdio.h>
#include <stdlib.h>

/* strcat函数：将字符串t复制到字符串s后面 */
void strcat(char *s, char *t);

int main(int argc, char *argv[])
{
    char s[50] = "hello";
    char *t = "world";

    printf("%s\t%s\n", s, t);
    strcat(s, t);
    printf("%s\n", s);

    return 0;
}


/* strcat函数：将字符串t复制到字符串s后面 */
void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
