// 串比较
//
// 不调用库函数，自己实现字符串的比较操作：该操作当比较的两个字符是都是字母，且两个字符互为大小写（如a和A、e和E）时认为两个字符相同，否则不同，其比较结果按这两个字符的原值确定。函数的返回值规定如下：
// 返回值 < 0：第一个不匹配的字符在 ptr1 中的值低于 ptr2 中的值
//	返回值 == 0：两个字符串的内容相等
//	返回值 > 0：第一个不匹配的字符在 ptr1 中的值大于在 ptr2 中的值
//
//	函数原型如下：
int str_compare(const char *ptr1, const char *ptr2);

#include "dsstring.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int str_compare(const char *ptr1, const char *ptr2)
{
    int i = 0;
    while (ptr1[i] == ptr2[i] || ptr1[i] + 32 == ptr2[i] || ptr1[i] - 32 == ptr2[i])
    {
        if (ptr1[i] == '\0' || ptr2[i] == '\0')
        {
            return 0;
        }
        i++;
    }
    return ptr1[i] - ptr2[i];
}
