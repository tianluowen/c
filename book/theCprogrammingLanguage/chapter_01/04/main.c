/*
 * 时间：2018年8月11日20:25:53
 * 目的：将摄氏温度转化为华氏温度输出
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* 温度下限 */
    upper = 300; /* 温度上限 */
    step = 20;   /* 步长 */

    printf("摄制温度转化华氏温度表\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0*celsius) / 5.0 + 32.0;
        printf("%3.0f  %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}

