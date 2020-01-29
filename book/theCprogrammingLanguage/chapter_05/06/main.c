/* 
    时间: 2020-01-29 16:05
    目的：采用指针而非数组索引的方式来重写一些函数
*/

#include <stdio.h>
#include <stdlib.h>

int getline_self(char *s, int lim);

int main(int argc, char *argv[])
{
    char str[128] = "\0";  
    int lengstr = 0;

    printf("请输入测试字符串: ");
    lengstr = getline_self(str, sizeof(str) - 1);
    printf("该字符串: %s 的长度为 %d\n", str, lengstr);

    return 0;
}


/* getline_self函数：读取一行字符串，返回长度 */
int getline_self(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 &&(c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    /* 决定计算不计算输入的回车符号 */
    /* if (c == '\n') */
    /*     *s++ = c; */
    *s = '\0';
    return s - t;
}

