/*
 * 时间：2019年11月9日23:47:03
 * 目的：找出字符串s1中第一次出现s2中的字符  返回位置
 */

#include <stdio.h>

#define MAXLINE 1000

//any函数：找出s1中最先出现s2中字符的位置
int any(char s1[], char s2[]);  

int main(int argc, char *argv[])
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("请输入源字符串: ");
    scanf("%s", s1);
    printf("请输入要查找的字符串: ");
    scanf("%s", s2);

    printf("%s 第一次出现在 %s 中的字符位置为: %d\n", s2, s1, any(s1, s2));

    return 0;
}

//any函数：找出s1中最先出现s2中字符的位置
int any(char s1[], char s2[])
{
    int i;
    int j;

    for (i=0; s1[i]!='\0'; i++)
    {
        for (j=0; s2[j]!='\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                break;
            }
        }
        if (s1[i] == s2[j])
        {
            return i+1;
        }
    }

    return -1;
}
