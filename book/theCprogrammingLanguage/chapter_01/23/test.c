/*
 * 时间：2018年8月22日10:38:05
 * 目的：编程程序实现对文件读写去除注释，写到另一个txt文件
 */

#include <stdio.h>
#include <stdlib.h>

void rcomment(int c, FILE *in, FILE *out);
void in_comment(FILE *in);
void echo_quote(int c, FILE *in, FILE *out);
void del_notes(FILE *in, FILE *out);

int main(int argc, char *argv[])
{
    FILE *in, *out;
    if ((in=fopen("test.c","r"))==NULL)
    {
        printf("无法打开此文件\n");
        exit(0);
    }
    if ((out=fopen("write.c", "w"))==NULL)
    {
        printf("无法打开此文件\n");
        exit(0);
    }

    int c;
    while ((c=fgetc(in))!=EOF)
    {
        rcomment(c, in, out);
    }

    fclose(in);
    fclose(out);
    printf("删除注释成功\n");

    return 0; 
}

/* rcoment：判断每一个字符，删除注释*/
void rcomment(int c, FILE *in, FILE *out)
{
    int d;
    if (c == '/')
    {
        if ((d=fgetc(in))=='*')  // /* 情况下 找出下一个 */
        {
            in_comment(in);
        }
        else if (d == '/')       // //情况下
        {
            del_notes(in, out);
        }
        else
        {
            fputc(c,out);
            fputc(d,out);
        }
    }
    else if (c=='\'' || c=='\"')
    {
        echo_quote(c, in, out);
    }
    else
    {
        fputc(c, out);
    }
}

/* in_comment：找到下一个对应的'*' '/'*/
void in_comment(FILE *in)
{
    int c, d;

    c = fgetc(in);
    d = fgetc(in);
    while (c!='*' || d!='/')
    {
        c = d;
        d = fgetc(in);
    }
}

/* echo_quote：*/
void echo_quote(int c, FILE *in, FILE *out)
{
    int d;

    fputc(c, out);
    while ((d=fgetc(in)) != c)
    {
        fputc(d, out);
        if (d == '\\')
        {
            fputc(fgetc(in), out);
        }
    }
}

/* del_notes:删除//后面的注释*/
void del_notes(FILE *in, FILE *out)
{
    int c, index;

    index = 1;

    while (index)
    {
        c = fgetc(in);
        if (c == '\\')
        {
            ++index;
        }
        else if (c == '\n')
        {
            --index;
        }
    }
    fputc(c, out);
}

