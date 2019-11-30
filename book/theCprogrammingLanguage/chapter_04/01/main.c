/*
 * date: 2019-11-18 21:10
 * desc: 
 */

#include <stdio.h>

/* strrindex函数：返回字符串 t 在 s 中最右边的位置，如果s中不包含t，则返回 -1 */
int strrindex(char s[], char t[]); 

int main(void)
{
    int n;
    /* 定义字符串 s 和 t，用来保存要查找的字符串t 和在字符串s中查找 */
    char s[100];
    char t[100];   

    printf("请输入文本字符串：");
    scanf("%s", &s);
    printf("请输入要查找的字符串：");
    scanf("%s", &t);

    n = strrindex(s, t);

    if (n == -1)
    {
        printf("字符串%s不在字符串%s之内\n", t, s);
    }
    else
    {
        printf("字符串%s在字符串%s最右边的位置是%d\n", t, s, n);
    }

    return 0;
}

/* strrindex函数：返回字符串 t 在 s 中最右边的位置，如果s中不包含t，则返回 -1 */
int strrindex(char s[], char t[])
{
    int i, j, k, pos;

    for (i=0; s[i] != '\0'; ++i)
    {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; ++j,++k)
        {
            NULL;
        }
        if (k > 0 && t[k] == '\0')
        {
            pos = i + 1;
        }
    }

    return pos;
}
