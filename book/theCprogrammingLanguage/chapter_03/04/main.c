/*
    时间：2018-8-9 19:54:38
    目的：编写一个在任意机器上运行都可以正确打印出一个数的绝对值 itoa
*/
#include <stdio.h>
#include <string.h>

#define abs(x) ((x)<0 ? -(x) : (x))

void itoa(int n, char s[]); //将n的绝对值输出
void reverse(char s[]);     //将字符串s颠倒
 
int main(int argc, char *argv[])
{
    int num = 100;
    char s[100];

    printf("请输入一个数: ");
    scanf("%d", &num);

    itoa(num, s);
    printf("该数的字符串形式为: ");
    puts(s);

    return 0;
}

/*itoa函数：将数n通过字符串s 输出n的绝对值*/
void itoa(int n, char s[]) 
{
    int i, sign;
    
    sign = n;
    i = 0;
    do 
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n/=10) != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}

/*reverse函数  将字符串s中的内容颠倒*/
void reverse(char s[])
{
    int i, n=strlen(s);
    char c;

    for (i=0; i<n/2; i++)
    {
        c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }
}
