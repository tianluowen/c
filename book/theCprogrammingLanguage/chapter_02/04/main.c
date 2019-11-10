/*
 * 时间：2018年5月4日16:55:12
 * 目的：删除字符串s1中包含s2的所有字符
 */

#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{

    char s1[MAXLINE];
    char s2[MAXLINE];
    int i;
    int j;
    int k;

    printf("请输入源字符串: ");
    scanf("%s", s1);
    printf("请输入要删除的字符合集: ");
    scanf("%s", s2);

    for (i=j=0; s1[i]!='\0'; i++)
    {

        for (k=0; s2[k]!='\0'; k++)  //判断过程
        {

            if (s1[i] == s2[k])
            {

                break;
            }
        }
        if (s2[k] == '\0')  //删除字符的过程
        {

            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';

    printf("删除结果为: ");
    printf("%s\n", s1);

    return 0;
}
