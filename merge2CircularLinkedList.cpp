typedef struct node
{
    int data;
    // 其他数据域成员
    struct node *next;
} NODE;

#define min(a, b) (((a) < (b)) ? (a) : (b))
bool operator<(const NODE &lhs, const NODE &rhs)
{
    return lhs.data < rhs.data;
}
bool operator==(const NODE &lhs, const NODE &rhs)
{
    return lhs.data == rhs.data;
}
bool operator<=(const NODE &lhs, const NODE &rhs)
{
    return lhs == rhs || lhs < rhs;
}
// struct cmp{
//     bool operator()(const NODE &lhs, const NODE &rhs) { return lhs.data > rhs.data; }
// };

NODE *merge2CircularLinkedList(NODE *head1, NODE *head2)
{
    if (head2->next == NULL)
        return head1;
    else if (head1->next == NULL && head2->next != NULL)
        return head2;
    NODE *L1 = head1, *L2 = head1->next, *R = head2, *CUR;
    while (L2 != head1 && R != head2)

    {
        if (L2->data <= R->data)
            L1 = L2, L2 = L2->next;
        else
            CUR = R->next, L1->next = R, L1 = R, R->next = L2, R = CUR;
    }
    if (L2 == head1)
    {
        L1->next = R;
        while (L1->next != head2)
            L1 = L1->next;
        L1->next = head1;
    }
    return head1;
}