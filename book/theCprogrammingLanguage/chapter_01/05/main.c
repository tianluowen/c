/* 
 * 时间：2018年8月18日10:55:50
 * 目的：逆序打印温度表
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int fahr;

    printf("逆序打印温度转化表\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {

        printf("%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr-32));
    }

    return 0;
}
