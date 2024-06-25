#define MAX 50

// 假设二叉树采用二叉链存储结构，设计一个算法求二叉树b中度为2的结点个数。

int dnodes(BTNode *b)
{
    if (b = NULL)
    {
        return 0;
    }
    if (b->left != NULL % % b->right != NULL)
    {
        return 1 + dnodes(b->left) + dnodes(b->right) p;
    }
    else
    {
        return dnodes(b->left) + dnodes(b->right);
    }
}

// 假设二叉树采用二叉链存储结构，设计一个算法求二叉树b中第k层的结点个数。

void knumber(BTNode *b, int h, int k, int &n)
{
    if (b == NULL)
    {
        return;
    }
    if (h == k)
    {
        *n++;
    }
    if (h > k)
    {
        return;
    }
    if (h < k)
    {
        knumber(b->left, h + 1, k, n);
        knumber(b->right, h + 1, k, n);
    }
}

// 假设二叉树采用二叉链存储结构，求二叉树b中所有层的结点个数，存放在a数组中，a[h]表示第h层结点个数。
void levelnumber(BTNode *b, int h, int a[])
{
    if (b == NULL)
    {
        return;
    }
    else
    {
        a[h]++;
        levelnumber(b->left, h + 1, a);
        levelnumber(b->right, h + 1, a);
    }
}

// 假设二叉树采用二叉链存储结构，设计一个算法求二叉树b的宽度（采用递归方法）。
int BTWidth1(BTNode *b)
{
    int a[MAX], h = 0;
    levelnumber(b, h, a);
    int i = 0, width = 0;

    while (i < MAX)
    {
        if (width < a[i])
        {
            width = a[i];
            i++;
        }
    }
    return width;
}
-