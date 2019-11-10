/*
 * 目的：将x从第p位开始的n位取反
 * 时间：2018年5月6日10:13:27
 */

#include <stdio.h>

/*invert函数：将x从第p位开始的n位取反*/
int invert(int x, int p, int n);
void binary(int a);

int main(int argc, char *argv[])
{
    int x;
    int p;
    int n;

    printf("例子: 21115 13 6\n");
    printf("请输入要操作的数 x:");
    scanf("%d", &x);
    printf("从哪一位开始操作 b:");
    scanf("%d", &p);
    printf("取反多少位 n:");
    scanf("%d", &n);

    printf("x 二进制为 :");
    binary(x);
    printf("\n");
    printf("取反结果为 :");
    binary(invert(x, p, n));
    printf("\n");

    return 0;
}

/*invert函数：将x从第p位开始的n位取反*/
int invert(int x, int p, int n)
{
    return x ^ ((~((~0)<<n))<<(p-n));
}

void binary(int a)
{
    if (a)
    {
        binary(a/2);
        printf("%d ", a%2);
    }
}
