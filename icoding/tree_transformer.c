// 树转二叉树
//
// 使用队列，编写transfrom函数，将普通树转换成对应的二叉树。

// 二叉树的相关定义如下
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} BiTNode, *BiTree;

// 普通树节点的定义如下：
#define MAX_CHILDREN_NUM 5
struct _CSNode
{
    DataType data;
    struct _CSNode *children[MAX_CHILDREN_NUM];
};
typedef struct _CSNode CSNode;
// 其中，子树的根节点的指针存放在children数组的前k个元素中，即如果children[i]的值为NULL，而children[i - 1]不为NULL，则表明该结点只有i棵子树，子树根结点分别保存在children[0]至children[i - 1]中。

// 队列相关定义及操作如下：
struct __Queue
{
    int i, j; // 指向数组内元素的游标
    void **array;
};
typedef struct __Queue Queue;

Queue *create_queue();                   // 创建队列
bool is_empty_queue(Queue *tree);        // 队为空返回true,不为空时返回false
void *del_queue(Queue *tree);            // 结点指针出队
void add_queue(Queue *tree, void *node); // 结点指针入队
void free_queue(Queue *tree);            // 释放队列
// transform函数定义如下：

BiTNode *transform(CSNode *root);

// 其中 root 为普通树的根结点，函数返回该树对应二叉树的根结点。

#include "bitree.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

BiTNode *transform(CSNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // 创建一棵二叉树，并将根节点的值赋值给二叉树的根节点
    BiTNode *H = (BiTNode *)malloc(sizeof(BiTNode));
    if (H == NULL)
    {
        exit(0);
    }
    H->data = root->data;
    H->left = NULL;
    H->right = NULL;

    // 创建一个队列，依次存放树广度优先遍历的节点的指针，和对应的二叉树节点中的指针
    Queue *Q = create_queue();
    add_queue(Q, root);
    add_queue(Q, H);

    // 广度优先遍历树，创建二叉树节点，并建立相应的连接关系
    while (!is_empty_queue(Q))
    {
        // 从队列中依次取出树中的节点和二叉树中的节点
        CSNode *TreeNode = (CSNode *)del_queue(Q);
        BiTNode *BNode_H = (BiTNode *)del_queue(Q);
        BiTNode *pre = NULL;

        // 遍历树中当前节点的所有孩子节点
        for (int i = 0; TreeNode->children[i] != NULL; i++)
        {
            // 创建一个新的二叉树节点，并将孩子节点的值赋值给它
            BiTNode *New = (BiTNode *)malloc(sizeof(BiTNode));
            if (New == NULL)
            {
                exit(0);
            }
            New->data = TreeNode->children[i]->data;
            New->left = NULL;
            New->right = NULL;

            // 第一个孩子作为上一个层节点的左孩子
            if (i == 0)
            {
                BNode_H->left = New;
                pre = New;
            }
            // 后面的孩子作为前面结点的右孩子
            else
            {
                pre->right = New;
                pre = New;
            }

            // 将当前孩子节点指针和对应二叉树中节点指针依次加入到队列中
            add_queue(Q, TreeNode->children[i]);
            add_queue(Q, New);
        }
    }

    // 释放队列占用的空间
    free(Q->array);
    free(Q);
    // 返回转换后的二叉树
    return H;
}