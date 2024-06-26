// 邻接表2
//
// 试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：

typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode;
typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} ListGraph;

int locate_vertex(ListGraph *G, VertexType v); // 返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v);   // 删除顶点 v
// 当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false。

#include "graph.h" //请勿删除，否则检查不通过
#include <stdio.h>

bool del_vertex(ListGraph *G, VertexType v)
{
    // 找到顶点在图中的位置
    int v1 = locate_vertex(G, v);
    if (v1 == -1)
    {
        return false; // 顶点不存在，返回false
    }

    // 删除与该顶点相关的边
    ArcNode *p1 = G->vertex[v1].firstarc; // 指向顶点的第一条边
    while (p1 != NULL)
    {
        ArcNode *temp = p1;                   // 保存当前边的指针
        G->vertex[v1].firstarc = p1->nextarc; // 修改顶点的第一条边指针
        p1 = p1->nextarc;                     // 指向下一条边
        free(temp);                           // 释放当前边的内存
        G->arcnum--;                          // 边数减一
    }

    // 删除顶点数组中该顶点
    for (int i = v1; i < G->vexnum; i++)
    {
        G->vertex[i] = G->vertex[i + 1];
    }
    G->vexnum--; // 顶点数减一

    // 更新其他顶点的邻接表
    ArcNode *p = NULL;
    for (int i = 0; i < G->vexnum; i++)
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            if (p->adjvex > v1)
            {                // 由于之前删除顶点数组中该顶点时移动了顶点数组中的元素，所以要更新链表中所有>v1的编号
                p->adjvex--; // 更新顶点位置，减一
                p = p->nextarc;
            }
            else if (p->adjvex == v1)
            {
                // 找到与顶点v相关的边
                if (G->vertex[i].firstarc == p)
                {
                    // 删除顶点v是第一条边的情况
                    ArcNode *temp = p;
                    G->vertex[i].firstarc = p->nextarc; // 修改顶点的第一条边指针
                    p = p->nextarc;                     // 指向下一条边
                    free(temp);                         // 释放当前边的内存
                }
                else
                {
                    // 删除顶点v不是第一条边的情况
                    ArcNode *pre = G->vertex[i].firstarc;
                    while (pre->nextarc != p)
                    {
                        pre = pre->nextarc;
                    }
                    ArcNode *temp = p;
                    pre->nextarc = p->nextarc; // 修改前一条边的指针
                    p = p->nextarc;            // 指向下一条边
                    free(temp);                // 释放当前边的内存
                }
                G->arcnum--; // 边数减一
            }
            else
            {
                p = p->nextarc;
            }
        }
    }
    return true; // 删除成功，返回true
}
