/*
 * 时间: 2020-01-28 17:50
 * 目的: 编写字符串函数strncpy strncat strbcmp
 */

#include <stdio.h>

int strlen(char *s); 
int strncmp(char *s, char *t, int n);
void strncpy(char *s, const char *t, int n);
void strncat(char *s, const char *t, int n);

int main(int argc, char *argv[]) 
{
    char s[128] = "hello world";
    char t[128] = "hello all!";
    char temp[128] = "hello world";

    printf("字符串 s: %s\n", s);
    printf("字符串 t: %s\n", t);
    printf("\n");

    printf("字符串 s: %s 的长度为 %d\n", s, strlen(s));
    printf("\n");

    printf("字符串 s: %s 和字符串 t: %s 前 10 个字节对比, 对比结果为 %d\n", s, t, strncmp(s, t, 10));
    printf("\n");

    strncat(s, t, strlen(t) + 1);
    printf("字符串 t: %s 的 %d 个字符复制到字符串 s: %s 的末尾\n结果为 s: %s\n", t, strlen(t), temp, s);
    printf("\n");
    
    strncpy(s, t, strlen(t) + 1);
    printf("字符串 t: %s 复制 %d 个字节到字符串 s: %s\n字符串 s: %s\n", t, strlen(t), temp, s);

    return 0;
}

int strlen(char *s)
{
    int i = 0;
    while (*s++)
        i++;

    return i;
}

/* strncpy函数：t中 n 个字符复制到 s 中 */
void strncpy(char *s, const char *t, int n)
{
    while (*t && n-- > 0)
    {
        *s++ = *t++;
    }
    while (n-- > 0)
        *s++ =  '\0';
}

/* strncat函数：t 中 n 个字节复制到 s 的末尾 */
void strncat(char *s, const char *t, int n)
{
    strncpy(s+strlen(s), t, n);
}

int strncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0' || --n <= 0)
            return 0;
    }
    return *s - *t;
}
