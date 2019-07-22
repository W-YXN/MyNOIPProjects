
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    // 其他数据域成员
    struct node *next;
} NODE;

NODE *reverseLinkedList(NODE *);

int main(int argc, char *argv[])
{

    /* 获取输入数据，细节隐藏不表 */
    NODE *head = NULL;
    NODE *node = new NODE;
    /* 构建原始链表，细节隐藏不表 */

    NODE *reversedHead = reverseLinkedList(head);

    /* 后续判题，细节隐藏不表 */
}

/* 你的代码将会被嵌入在这个部分 */
NODE *reverseLinkedList(NODE *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    NODE *tmp = head;
    head = head->next;
    tmp->next = NULL;
    while (head->next != NULL)
    {
        NODE *temp = tmp;
        tmp = head;
        head = head->next;
        tmp->next = temp;
    }
    if (head->next == NULL)
    {
        NODE *temp = tmp;
        tmp = head;
        tmp->next = temp;
        return head;
    }
}