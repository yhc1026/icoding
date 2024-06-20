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
    int i = 0, j = L->last;
    while (1)
    {
        if (i >= j)
        {
            break;
        }
        if ((L->elem[i]) % 2 == 0 && (L->elem[j]) % 2 == 1)
        {
            int t = 0;
            t = L->elem[i];
            L->elem[i] = L->elem[j];
            L->elem[j] = t;
            i++;
            j--;
        }
        else if ((L->elem[i]) % 2 == 1 && (L->elem[j]) % 2 == 0)
        {
            i++;
            j--;
        }
        else if ((L->elem[i]) % 2 == 1 && (L->elem[j]) % 2 == 1)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
