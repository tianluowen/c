/*
 * 时间：2018年8月21日10:21:18
 * 目的：编写函数reverse(s)
 * 功能：将字符串s中的字符颠倒输出
 */

#include <stdio.h>

#define MAXLINE 1000                   /*设置的最大接收一行字符的数量*/

int getlin(char line[], int maxline); /*获取一行字符的函数         */
void reverse(char s[]);                /*将字符串s翻转             */

int main(int argc, char *argv[])
{
    char line[MAXLINE];                /*当前行的输入              */

    while (getlin(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s\n", line);
    }
        
    return 0;
}

/* getlin: 获取一行字符的函数 */
int getlin(char line[], int maxline)
{
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar()) != '\n' && c != EOF; ++i)
    {

        if (i < MAXLINE-2)
        {
            line[j] = c;
            ++j;
        }
    }
    if (c == '\n')
    {
        line[j] = c;
        ++j;
        ++i;
    }
    line[j] = '\0';

    return i;
}

/* reverse：将字符串s翻转  */
void reverse(char s[])               
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    --i;
    j = 0;
    while (j < i)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++j;
        --i;
    }
}
