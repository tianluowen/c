/*
 * 目的：不使用逻辑运算符实现一个for循环
 * 时间：2018年5月4日11:19:11
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; +++i) 改写  
    */
    int i = 0;
    int lim = 100;
    char ch[100];
    int c;

    while (i < (lim-1))
    {
        c = getchar();
        if (c == EOF)
        {
            break;
        }
        else if (c == '\n')
        {
            break;
        }
        ch[i] = c;   //先后顺序 以及while  还有 if else if 用的都很好  
    }

    return 0;
}
