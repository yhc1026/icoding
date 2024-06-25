#define MAX 50
#define INF 999
// 假设图采用邻接矩阵表示。设计一个从顶点v出发的深度优先遍历算法。
int visited[MAX] = 0;

void MDFS(MGraph g, int v)
{
    int w = 0;
    visited[v] = 1;
    printf("%d", v);
    for (w = 0; w < g.vexnum; w++)
    {
        if (g.arr[v][w] != 0 && g.arr[v][w] != 999)
        {
            MDFS(g, w);
        }
    }
}

// 假设图采用邻接表表示。设计一个从顶点v出发的深度优先遍历算法。
void DFS2(ALGraph *G, int v, int &vn, int &en)
{
    Enode *p = G->Alist[v].firstedge;
    visited[v] = 1;
    vn++;
    while (vn != G->vexnum)
    {
        en++;
        if (visited[p->adjvex == 0])
        {
            DFS2(G, p->adjvex, vn, en);
        }
        p = p->next;
    }
}

// 假设一个连通图有向采用邻接表作为存储结构。试设计一个算法，判断其中是否存在回路。
void Cycle(ALGraph *G, int v, bool &has)
{
    Enode *p = G->adjlist[v].firstedge;
    visited[v] = 1;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (visited[w] == 0)
        {
            Cycle(G, w, has);
        }
        else
        {
            has = true;
        }
        p = p->next;
    }
}
bool HasCycle(ALGraph *G)
{
    bool *has = false;
    int i = G->numnodes;
    while (i < G->numnodes)
    {
        Cycle(G, i, has);
        if (has == true)
        {
            return true;
        }
    }
    return false;
}