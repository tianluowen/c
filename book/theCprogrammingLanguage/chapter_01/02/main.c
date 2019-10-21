/*
 * 时间：2019年10月19日21:14:30
 * 目的；观察转义字符的输出以及效果
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* 两个@之间的内容即为转义字符的效果 */
    printf("两个@之间的内容即为转义字符的效果\n");
    printf("This is:\\n\n");
    sleep(1);
    printf("@\n@\n");

    printf("This is:\\s\n");
    sleep(1);
    printf("@\s@\n");

    printf("This is:\\~\n");
    sleep(1);
    printf("@\~@\n");
    
    printf("This is:\\9\n");
    sleep(1);
    printf("@\9@\n");
    
    printf("This is:\\x50\n");
    sleep(1);
    printf("@\x50@\n");
    
    printf("This is:\\114\n");
    sleep(1);
    printf("@\114@\n");
    
    printf("This is:\\t\n");
    sleep(1);
    printf("@\t@\n");
    
    return 0;
    return 0;
}
