/*
    时间：2018年8月18日15:32:56
    目的：测试统计字符
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
    char c;
    int danci = 0;
    int num   = 0;
    int zifu  = 0;
    int lin   = 0;

    printf("请输入要测试的字符串：\n");
    while ((c = getchar()) != EOF)
    {
        ++zifu;
        if (c == '\n')
        {
            ++lin;
        }
        if (('A' <= c&&c <= 'Z') || ('a' <= c&&c <= 'z'))
        {
            if (danci==0)
            {
                danci =  1;
                num++;
            }
        }
        else
        {
            danci = 0;
        }
    }
    printf("单词=%d 字符=%d 行数=%d\n", num, zifu, lin);

    return 0;
}
