/***
* 
*   时间：2018年9月13日13:14:41
*   目的：扩充函数 atof，
*
***/

#include <stdio.h>

double atof(char s[]); // atof函数：把字符串转换成相应的数据

int main(int argc, char *argv[])
{
    char s[1000];      //定义变量存储字符，与转换后的数据
    double num;

    printf("请输入要转换的字符串：");  //键盘输入
    scanf("%s", s);

    num = atof(s);

    printf("%f\n", num);

    return 0;
}

//atof函数：把字符串转换成相应的数据
double atof(char s[])
{
    double val, power;
    int exp, i, sign;
    
    for (i=0; s[i]=='\0'; i++)  //处理前面的空格
    {
        NULL;
    }
    sign = (s[i]=='-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')  //跳过符号这个字符
    {
        ++i;
    }
    for (val = 0.0; '0'<=s[i] && s[i]<='9'; i++)
    {
        val = val * 10 + s[i] - '0';
    }
    if (s[i] == '.')
    {
        ++i;
    }
    for (power=1.0; '0'<=s[i] && s[i]<='9'; i++)
    {
        val = val * 10 + s[i] - '0';
        power *= 10;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E')   //判断 e 或者 E 和面的次方 大小
    {
        ++i;
        sign = (s[i]=='-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')  //跳过符号这个字符
        {
            ++i;
        }
        for (exp = 0; '0'<=s[i] && s[i]<='9'; i++)
        {
            exp = exp * 10 + s[i] - '0';
        }
        if (sign == 1)
        {
            while (exp-- > 0)
            {
                val *= 10;
            }
        }
        else
        {
            while (exp-- > 0)
            {
                val /= 10;
            }
        }
    }

    return val;
}

/************************************************************************/
/*  
    时间：2018年9月13日15:58:47
    结果：
    请输入要转换的字符串：-456.457e-4
    -0.045646
    请按任意键继续. . .
*/
/************************************************************************/
