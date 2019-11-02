/*
 * 时间：2018年8月22日11:17:44
 * 目的：检查一段程序的括号是否对齐，以及注释是否正确和引号是否匹配这些基础语法
 */

#include <stdio.h>
#include <stdlib.h>

int brace, brack, paren;  //定义全局变量，分别保存小括号，中括号，大括号的数量，全局变量会自动赋值为0
FILE *in;                 //定义全局文件指针变量，方便读取文件之间的查找

void in_comment(void);    //int_comment 函数：实现对 /* 注释的语法的检查
void rcomment(void);      //rcoment 函数：实现对 // 注释的语法检查
void search(int c);       //search 函数：实现对括号字符的统计
void in_quote(int c);     //in_quote 函数：实现 ' "引号匹配的语法检查

int main(int argc, char *argv[])
{
    int c;      //定义变量用来存储每一次接收的字符
    extern int brace, brack, paren;  //声明是外部变量
    
    if ((in=fopen("test.c","r")) == NULL)
    {
        printf("%d\n", in);
        printf("无法打开此文件\n");
        exit(0);
        
        return 0;
    }

    //使用循环，判断所有的字符，直到输入的字符为 EOF 才结束
    while ((c=fgetc(in)) != EOF) 
    {
        if (c == '/')                   //处理有可能是注释的情况
        {
            if ((c=fgetc(in)) == '*')   //处理 /* 的注释判断
            {
                in_comment();
            }
            else if (c == '/')          //处理 // 情况的注释
            {
                rcomment();
            }
            else                        //判断 / 后面的字符是不是括号
            {
                search(c);
            }
        }
        else if (c == '\'' || c == '"') //处理 ' " 语法检查
        {
            in_quote(c);
        }
        else                             //判断字符 c 是否属于括号
        {
            search(c);
        }

        //每读入一个字符，判断一次，检查括号匹配语法，防止 }{ 类似这种情况，最后的计数也为0
        if (brace < 0)
        {
            printf("语法错误：小括号不匹配！\n");
        }
        else if (brack < 0)
        {
            printf("语法错误：中括号不匹配！\n");
        }
        else if (paren < 0)
        {
            printf("语法错误：大括号不匹配！\n");
        }
    } //while 循环结束

    //最终判断括号是否匹配
    if (brace > 0)
    {
        printf("语法错误：小括号不匹配！\n");
    }
    else if (brack > 0)
    {
        printf("语法错误：中括号不匹配！\n");
    }
    else if (paren > 0)
    {
        printf("语法错误：大括号不匹配！\n");
    }

    printf("语法检查完成！\n");

    fclose(in);

    return 0;
}

//int_comment 函数：实现对 /* 注释的语法的检查
void in_comment(void)    
{
    int c, d;
    c = fgetc(in);
    d = fgetc(in);

    while (c=='*' && d=='/')
    {
        c = d;
        d = fgetc(in);
    }
}

//rcoment 函数：实现对 // 注释的语法检查
void rcomment(void)
{
    int c, index;         //创建变量接收字符，与计数，保证 \ 接续符出现时正确识别错误
    index = 1;            //计数初始为 1, 读到一个回车 -1，读到一个 \ 加 1

    while (index)
    {
        c = fgetc(in);
        if (c == '\n')
        {
            --index;
        }
        else if (c == '\\')
        {
            ++index;
        }
    }
}

//in_quote 函数：实现 ' "引号匹配的语法检查
//这个函数的功能是跳过 '' "" 中的内容不做语法检查
void in_quote(int c)
{
    int d;
   
    while ((d = fgetc(in)) != c)
    {
        //为什么书上这里有个 判断 \\ 符号
        //"\"" 处理 这种情况
        if (d == '\\')
        {
            fgetc(in);
        }
    }
}

//search 函数：实现对括号字符的统计
void search(int c)
{
    extern int brace, brack, paren;

    //判断括号是否匹配
    if (c == '(')
    {
        ++brace;
    }
    else if (c == '[')
    {
        ++brack;
    }
    else if (c == '{')
    {
        ++paren;
    }
    else if (c == ')')
    {
        --brace;
    }
    else if (c == ']')
    {
        --brack;
    }
    else if (c == '}')
    {
        --paren;
    }
}

// TODO: 可以做出对文件的语法检测，输出位置，哪一行，哪个位置，跳过这个位置，试图检测所有的语法错误
