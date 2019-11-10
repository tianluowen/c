/*
 * 目的：对比两款折中查找的速度
 * 时间：2018年5月6日17:20:26
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

/* binsearch_a函数：折半查找函数 */
int binsearch_a(int x, int v[], int n);
/* binsearch_b函数：折半查找函数 */
int binsearch_b(int x, int v[], int n);

int main(int argc, char *argv[])
{
    int a[10] ={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    /* clock_t start, finsh; */
    double time; 
    struct timeval start, finsh;
    
    // start = clock();
    gettimeofday(&start, NULL);
    for (int i=0; i<100000; i++)
    {
        binsearch_a(3, a, sizeof(a)/sizeof(int));
    }
    printf("这个数是第%d个数\n", binsearch_a(3, a, sizeof(a)/sizeof(int)));
    // finsh = clock();
    gettimeofday(&finsh, NULL);
    // time = finsh - start;
    time = finsh.tv_usec - start.tv_usec;
    printf("原来的程序所花费时间为%f\n", (double)time);

    // start = clock();
    gettimeofday(&start, NULL);
    for (int i=0; i<100000; i++)
    {
        binsearch_b(3, a, sizeof(a)/sizeof(int));
    }
    printf("这个数是第%d个数\n", binsearch_b(3, a, sizeof(a)/sizeof(int)));
    // finsh = clock();
    gettimeofday(&finsh, NULL);
    // time = finsh - time;
    time = finsh.tv_usec - start.tv_usec;
    printf("改写后程序所花费时间为%f\n", (double)time);

    return 0;
}

/* binsearch_a函数：折半查找函数 */
int binsearch_a(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n-1;
    while (low<=high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
            return mid+1;
    }
    return -1;
}

/* binsearch_b函数：折半查找函数 */
int binsearch_b(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while ((low<=high) && (x!=v[mid]))
    {
        mid = (low+high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (x==v[mid])
    {
        return mid+1;
    }
    return -1;
}

/*
 * 小结：
 * 输出结果是微妙
 * 由此可见，两种方案的执行时间并没有太多的差异，但是修改后却失去了代码的可读性。
 */
