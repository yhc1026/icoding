void Reverse(LinkNode *&L)
{
    LinkNode *p, *q;
    p = L->next->next;
    q = L->next->next->next;
    L->next->next = NULL;
    while (P != NULL)
    {
        p->next = L->next;
        L->next = p;
        p = q;
        q = q->next;
    }
}