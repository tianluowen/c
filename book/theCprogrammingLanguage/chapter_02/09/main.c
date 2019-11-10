/*
 * 目的：重写bitcount函数
 * 时间：2018年5月6日13:54:29
 */

#include <stdio.h>

/* bitcont函数：求出x的2进制位有多少个1 */
int bitcount(int x);
void binary(unsigned int a);

int main(int argc, char *argv[])
{
    int a;
    int temp;

    printf("请输入要操作的数 x:");
    scanf("%d", &a);
    temp = a;

    printf("a 的二进制新式为: ");
    binary(a);
    printf("\n");
    printf("%d 进制位为1的数量为: %d\n", a, bitcount(temp));

    return 0;
}

/* bitcont函数：求出x的2进制位有多少个1 */
int bitcount(int x)
{
    int i = 0;

    while (x)
    {
        x &= (x-1);
        i++;
    }
    return i;
}

void binary(unsigned int a)  // unsigned 不管值得大小  只输出二进制位
{
    if (a)
    {
        binary(a/2);
        printf("%d ", a%2);
    }
}
