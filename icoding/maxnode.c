// 设计一个算法，删除一个单链表L中元素值最大的结点（假设最大值结点是唯一的）。
#include<stdio.h>

void delmaxnode(LinkNode *L)
{
    LinkNode*p = L->next, pmax=L, maxpre1=L, maxpre2=L;
    while(p!=NULL)
    {
    if(p->data>pmax->data)
        {
            pmax=p;
            maxpre2=maxpre1;
        }
        p=p->next;
        maxpre1=maxpre1->next;
    }

    maxpre2->next=pmax->next;
    free(pmax);
    pmax=NULL;
}
