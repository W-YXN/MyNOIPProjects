#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *insertLinklist(NODE *head, int tar, int val);
NODE *deleteLinklist(NODE *head, int tar);

NODE *insertLinklist(NODE *head, int tar, int val)
{
    if (head == NULL)
    {
        NODE *tmp = new NODE;
        tmp->data = val;
        tmp->next = NULL;
        head = tmp;
        return head;
    }
    else
    {
        NODE *tmp = new NODE;
        tmp->data = val;
        NODE *ppp = head;
        while (ppp->data != tar)
        {
            ppp = ppp->next;
        }
        tmp->next = ppp->next;
        ppp->next = tmp;
        return head;
    }
}

NODE *deleteLinklist(NODE *head, int tar)
{
    if (head == NULL)
        return head;
    if (head->data == tar)
    {
        head = head->next;
        return head;
    }
    NODE *papapa = head;
    while (papapa->next->data != tar)
    {
        papapa = papapa->next;
    }
    papapa->next = papapa->next->next;
    return head;
}