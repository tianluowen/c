/*
 * 时间：2018年5月8日16:32:11
 * 目的：编写函数expand
 */

#include <stdio.h>

/*expande函数：将字符串1的内容扩展*/
void expande(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    char s[200];
    char t[200];

    printf("请输入源字符串: ");
    scanf("%s", s);
    
    expande(s, t);
    printf("输入字符串为: %s\n", s);
    printf("扩展字符串为: %s\n", t);

    return 0;
}

/* expande函数：将字符串1的内容扩展 */
void expande(char s1[], char s2[])
{
    char c;
    int i = 0; 
    int j = 0;

    while ((c = s1[i++]) != '\0') //不到结束符
    {
        if (s1[i] == '-' && s1[i+1] >= c)
        {
           i++; 
           while (c < s1[i])
           {
               s2[j++] = c++;
           }
        }
        else
        {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}

