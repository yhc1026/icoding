// 层序遍历

void new_order(BiTree root)
{
    Stack *S1, *S2;
    init_stack(S1);
    init_stack(S2);
    BiTree cur = NULL;
    push(S1, root);
    while (!is_empty(S1) || !is_empty(S2))
    {
        while (!is_empty(S1))
        {
            pop(S1, &cur);
            visit_node(cur);
            if (cur->left != NULL)
            {
                push(S2, cur->left);
            }
            if (cur->right != NULL)
            {
                push(S2, cur->right);
            }
        }
        while (is_empty(S1) && !is_empty(S2))
        {
            pop(S2, &cur);
            push(S1, &cur);
        }
    }
}
