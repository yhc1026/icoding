// 链表 删除范围内结点
//
// 已知线性表中的元素（整数）以值递增有序排列，并以单链表作存储结构。试写一高效算法，删除表中所有大于mink且小于maxk的元素（若表中存在这样的元素），分析你的算法的时间复杂度。

// 链表结点定义如下：
struct _lnklist
{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

// 函数原型如下：
// void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
//
// 其中L指向链表的头结点。

#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    LinkList node = L;
    L = L->next;
    while (L->next != NULL)
    {
        if (L->data > mink && L->data < maxk)
        {
            node->next = L->next;
            free(L);
            L = node->next;
        }
        else
        {
            L = L->next;
            node = node->next;
        }
    }
}