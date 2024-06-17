// 串替换
// 不调用库函数，自己实现字符串替换操作，函数原型为：
//
// int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr);
// 参数说明:
//
// in， 原始字符串，保持不变
// out, 存放替换结果的字符串
// outlen，out空间的大小
// oldstr，要替换的旧字符串
// newstr，替换成的新字符串
// 函数返回成功替换的次数，即有多少个子串被成功替换
// 在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
// 原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
// 如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。此时函数应该返回 2, out指向的串为 "aaabbb333333c"
// 再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "b"，newstr 为 "123456"，进行替换后所得的串长度为14，与结束符一共占 15 个字节，超过outlen的10字节，此时不进行替换，函数应该返回 0。

#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int sz1 = sizeof(in) / sizeof(in[0]);
    int sz2 = sizeof(oldstr) / sizeof(oldstr[0]);
    int sz3 = sizeof(newstr) / sizeof(newstr[0]);
    int cnt = (outlen - sz1) / (sz3 - sz2);
    if (cnt > 0)
    {
        return cnt;
    }
    int n = 0;
    while(in[n]!='\0')
    {
        out[n] = in[n];
    }
    int i = 0;
    int t = 0;
    while (in[i] != '\0')
    {
        while (i < sz1 && t < sz2)
        {
            if (in[i] != oldstr[t])
            {
                int j = t - 1;
                t = 0;
                i = i - j;
            }
            i++;
            t++;
        }
        i = i - sz3;
        for (i = 0; i < sz3; i++)
        {
            out[i] = newstr[i];
        }
    }
}