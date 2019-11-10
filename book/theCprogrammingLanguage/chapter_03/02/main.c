/*
 * 目的：编写函数escape(s, t)
 * 时间：2018年5月7日16:56:26
 */

#include <stdio.h>
#include <string.h>

/* escape函数：将转移字符转换为可见的字符形式 */
void escape(char s[], char t[]);
/* unescape函数：将可见的字符转换为转义字符 */
void unescape(char s[], char t[]);

int main(int argc, char *argv[])
{
    char s[100] = "shghf\ngfhg\tgkf\tghg";
    char t[100];

    printf("%s\n", s);
    printf("字符串长度为: %d\n", strlen(s)); 
    printf("\n");
    
    escape(s, t);
    printf("转换后的结果为:");
    printf("%s\n", t);
    printf("\n");

    unescape(t, t);
    printf("转换后的结果为:");
    printf("%s\n", t);

    return 0;
}

/*escape函数：将转移字符转换为可见的字符形式*/
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while ('\0' != s[i])
    {
        if (s[i] == '\n')
        {
            t[j++] = '\\';
            t[j++] = 'n';
            ++i;
        }
        else if (s[i] == '\t')
        {
            t[j++] = '\\';
            t[j++] = 't';
            ++i;
        }
        else
        {
            t[j++] = s[i++];
        }
    }
    t[j] = '\0';
}

/*unescape函数：将可见的字符转换为转义字符*/
void unescape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '\\')
        {
            ++i;
            switch (s[i++])
            {
            case 't':
                t[j++] = '\t';
                break;
            case 'n':
                t[j++] = '\n';
                break;
            default:
                printf("未知错误\n");
            }
        }
        else
        {
            t[j++] = s[i++];
        }
    }
}
