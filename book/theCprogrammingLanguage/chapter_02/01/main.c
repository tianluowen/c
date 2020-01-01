/*
 * 目的：打印int char 的极限
 * 时间：2018年5月4日10:00:00
 */

#include <stdio.h>
#include <limits.h>  //包含一些基本类型的极限值

int main(int argc, char *argv[])
{
    printf("usigned char max=%u\tusigned char min=%u\n", UCHAR_MAX, 0);
    printf("signed char max=%d\tsigned char min=%d\n", SCHAR_MAX, SCHAR_MIN);
    printf("char max=%d\tchar min=%d\n", CHAR_MAX, CHAR_MIN);
    printf("\n");

    printf("usigned int max=%u\tusigned int min=%u\n", UINT_MAX, 0);
    printf("signed int max=%d\tsigned int min=%d\n", INT_MAX, INT_MIN);
    printf("\n");

    printf("usigned short max=%u\tusigned short min=%u\n", USHRT_MAX, 0);
    printf("signed short max=%d\tsigned short min=%d\n", SHRT_MAX, SHRT_MIN);
    printf("\n");

    printf("usigned long max=%lu\tusigned long min=%d\n", ULONG_MAX, 0);
    printf("signed long max=%ld\tsigned long min=%ld\n", LONG_MAX, LONG_MIN);
    printf("\n");

    return 0;
}
