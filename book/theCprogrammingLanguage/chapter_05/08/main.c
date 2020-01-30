/*
 * 时间: 2020-01-29 21:09
 * 目的: 使用指针的方式代替数组的方式改写函数
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int day_of_year(int year, int month, int day)
{
    if (year < 0)
    {
        return EXIT_FAILURE;
    }
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (month <= 0 || month > 12 || day < 0 || day > daytab[leap][month])
    {
        return EXIT_ERROR;
    }
    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year <= 0 || yearday <= 0)
    {
        return EXIT_ERROR;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday > 365 + leap)
    {
        return EXIT_ERROR;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int year = 2001;
    int month = 2;
    int day = 15;
    int days = 0;
    int res = 0;

    days = day_of_year(year, month, day);
    if (days == EXIT_ERROR)
    {
        printf("输入参数有误，请重新输入！\n");
    }

    printf("%d 年 %d 月 %d 天是今年的 %d 天!\n", year, month, day, days);

    res = month_day(year, days, &month, &day);
    // res = month_day(year, days, &month, &day);
    if (res == EXIT_ERROR)
    {
        printf("输入参数有误，请重新输入!\n");
    }

    printf("%d 年 %d 天是今年的 %d 月 %d 天!\n", year, days, month, day);

    return EXIT_SUCCESS;
}

