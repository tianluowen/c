/*
 *目的：对x执行下列操作  将x中从第p为开始的n个2进制位设置为y中最右边n位的值
     x其余各位保持不变
 *时间：2018-5-5 19:17:33
*/

#include <stdio.h>

/*函数setbits:对x执行下列操作  将x中从第p为开始的n个2进制位设置为y中最右边n位的值
              x其余各位保持不变*/
int setbits(int x, int p, int n, int y);

/*h函数binary：将十进制数a转换为2进制位输出*/
void binary(int a);

int main(int argc, char *argv[])
{
    int x;
    int p;
    int n;
    int y;

    printf("例子: 653 8 4 123\n");
    printf("请输入要操作的数 x:");
    scanf("%d", &x);
    printf("从哪一位开始设置 b:");
    scanf("%d", &p);
    printf("替换多少位 n:");
    scanf("%d", &n);
    printf("替换的数 y:");
    scanf("%d", &y);
    printf("\n");

    printf("x 二进制为 :");
    binary(x);
    printf("\n");
    printf("y 二进制为 :");
    binary(y);
    printf("\n");
    printf("替换结果   :");
    binary(setbits(x, p, n, y));
    printf("\n");

    return 0;
}

int setbits(int x, int p, int n, int y)
{
    // return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
    // 课后答案是这样，但是这样计算下来是从第 n+1 位开始唯一的
    return x & ~(~(~0 << n) << (p-n)) | (y & ~(~0 << n)) << (p-n);
}

void binary(int a)
{
    if (a)
    {
        binary(a/2);
        printf("%d ", a%2);
    }
}
