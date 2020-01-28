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
    char s[128] = "\0";
    char t[128] = "\0";


    printf("请输入源始字符串 s: ");
    scanf("%s", s);
    printf("请输入要在 s 后面添加的字符串 t: ");
    scanf("%s", t);

    printf("\n");
    printf("字符串 s 为: %s\n字符串 t 为: %s\n", s, t);
    strcat(s, t);
    printf("拼接后的字符串为: %s\n", s);

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
