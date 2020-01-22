/*
* 时间: 2020-01-22 15:09
* 目的: 定义swap(t, x, y)宏，用来交换t类型的两个变量
*/

#include <stdio.h>

#define SWAP(t, x, y) { t _z;  \
                        _z = y;\
                        y = x; \
                        x = _z;}

int main(int argc, char *argv[])
{
    int x = 3;
    int y = 4;

    printf("交换前: x=%d,y=%d\n", x, y);
    SWAP(int, x, y);
    printf("交换后: x=%d,y=%d\n", x, y);

    return 0;
}
