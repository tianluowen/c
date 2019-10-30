/*
 * 时间：2018年8月20日19:52:41
 * 目的：打印输入每个字符的频率
 */

#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15     /*定义每个字符出现的最大频率*/
#define MAXCHAR 128    /*定义可显示的字符集       */

int main(int argc, char *argv[])
{
    int c, i;
    int len;
    int cc[MAXCHAR];

    printf("提示：windows 下使用 CTRL + z  unix linux mac 下使用 CTRL + d 结束输入\n");
    printf("请输入要测试的字符串\n");

    for (i=0; i<MAXCHAR; ++i)       /*初始化所有字符个数都为0*/
    {
        cc[i] = 0;
    }
    while (EOF != (c=getchar()))    /*将所有输入字符判断统计 */
    {
        if (c < MAXCHAR)
        {
            ++cc[c];
        }
    }

    for (i=1; i<MAXCHAR; ++i)      /*输出                  */
    {
        printf("%5d - %c - %d", i, i, cc[i]);
        len = cc[i];
        while (len>0)
        {
            printf(" * ");
            --len;
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

