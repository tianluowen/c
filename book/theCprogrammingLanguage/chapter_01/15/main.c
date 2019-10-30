/*
 * 时间：2018年8月20日20:09:15
 * 目的：将温度转换输出以函数的形式输出
 */

#include <stdio.h>

float celsius(float fahr);   /*温度转换函数*/

int main(int argc, char *argv[])
{
    float fahr;
    int lower, upper, step;

    lower = 0;       /*最低温度*/
    upper = 300;     /*最高温度*/
    step  = 20;      /*步长*/
    
    fahr = lower;    /*输出*/
    while (fahr < upper)
    {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr += 20;
    }

    return 0;
}

float celsius(float fahr)   /*温度转换函数*/
{
    return (5.0/9.0)*(fahr-32.0);
}

