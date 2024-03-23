队列 循环链表表示队列

// 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：
//
//
// 1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue * LQ);
//
// 2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue * LQ, ElemType x);
//
// 3: 出队列，成功返回真，且 * x为出队的值，否则返回假 bool leave_queue(LinkQueue * LQ, ElemType * x);
//
// 相关定义如下：

#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

    typedef struct _QueueNode
{
    ElemType data;           // 数据域
    struct _QueueNode *next; // 指针域
} LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue *LQ)
{
    (*LQ) = (LinkQueue *)malloc(sizeof(LinkQueueNode));
    if ((*LQ) == NULL)
    {
        return false;
    }
    (*LQ)->next = *LQ;
    return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
    LinkQueue newnode = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (newnode == NULL)
    {
        return false;
    }
    newnode->next = (*LQ)->next;
    (*LQ)->next = newnode;
    *LQ = newnode;
    newnode->data = x;
    return true;
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
    LinkQueue head = *LQ->next;
    LinkQueue next = head->next;
    *x = next->data;
    *LQ->next = next->next;
    if (next)
        free(next);
    next = NULL;
    return true;
}