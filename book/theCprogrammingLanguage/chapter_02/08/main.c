/*
 * 目的：编写函数rightrot（x， n）循环右移n位
 * 时间：2018年5月6日10:47:38
 */

#include <stdio.h>

/*rightrot函数：将x循环右移n位*/
unsigned int rightrot(unsigned int x, int n);
void binary(unsigned int a);

int main(int argc, char *argv[])
{
    int x;
    int n;

    printf("例子: 15 1\n");
    printf("请输入要操作的数 x:");
    scanf("%d", &x);
    printf("从哪一位开始操作 n:");
    scanf("%d", &n);

    printf("x 二进制为 :");
    binary(x);
    printf("\n");
    printf("移动结果为 :");
    binary(rightrot(x, n));
    printf("\n");

    return 0;
}

/* binary函数：打印传入数的二进制 */
void binary(unsigned int a)  //unsigned 不管值得大小  只输出二进制位
{
    if (a)
    {
        binary(a/2);
        printf("%d ", a%2);
    }
}

/* rightrot函数：将x循环右移n位 */
unsigned int rightrot(unsigned int x, int n)
{
    int rbit;
    while (n>0)
    {
        rbit = (x & 1) << (sizeof(x)*8 - 1);
        x >>=1;
        x |= rbit;

        --n;
    }
    return x;
}
