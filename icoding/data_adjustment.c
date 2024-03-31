// 顺序表 数据调整
//
// 已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数.
// 要求算法的时间复杂度为O(n), 空间复杂度为O（1）。
// 函数原型如下：
// void odd_even(SeqList* L);
//
// 相关定义如下：

struct _seqlist
{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void odd_even(SeqList *L)
{
    int size = (L->last) - 1;
    int t = 0;
    int x = 0;
    while (t < size && x + t < size - 1)
    {
        if (L->elem[t] % 2 == 0)
        {
            int n = L->elem[t];
            L->elem[t] = L->elem[size - x];
            L->elem[size - x] = n;

            x++;
        }
        else
        {
            t++;
        }
    }
}
