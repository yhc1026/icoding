// 邻接矩阵
//
// 试在邻接矩阵存储结构上实现图的基本操作 matrix_insert_vertex 和matrix_insert_arc，相关定义如下：

typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct
{
    VertexType vertex[MAX_VERTEX_NUM];        // 顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum;                       // 图的当前顶点数和弧数
    GraphType type;                           // 图的种类标志
} MatrixGraph;

int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); // 返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。

#include "graph.h" // 请不要删除，否则检查不通过
#include <stdio.h>

bool matrix_insert_vertex(MatrixGraph *G, VertexType v)
{
    if (G->vexnum == MAX_VERTEX_NUM || G == NULL)
    {
        return false;
    }
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->vertex[i] == v)
        {
            return false;
        }
    }
    int sz = G->vexnum;
    G->vertex[sz] = v;
    ++(G->vexnum);
    for (int t = 0; t < G->vexnum; t++)
    {
        G->arcs[t][sz] = 0;
        G->arcs[sz][t] = 0;
    }
    return true;
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w)
{
    if (G == NULL)
    {
        return false;
    }

    int v1 = matrix_locate_vertex(G, v);
    int v2 = matrix_locate_vertex(G, w);

    if (v1 == -1 || v2 == -1)
    {
        return false;
    }

    if (G->type == DG)
    {
        if (G->arcs[v1][v2] != -1)
        {
            return false;
        }
        G->arcs[v1][v2] = 1;
    }
    else
    {
        if (G->arcs[v1][v2] != -1)
        {
            return false;
        }
        G->arcs[v1][v2] = 1;
        G->arcs[v2][v1] = 1;
    }
    G->arcnum++;
    return true;
}