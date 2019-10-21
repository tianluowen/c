/*
 * 时间：2018-8-11 20:16:56
 * 目的：温度转换表
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20;   /* 步长 */

    printf("温度转换表\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
