#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *val;
    struct node *next;
} node_t;

node_t createList(int nodec, char *nodes[]);
void printList(node_t *head);

node_t createList(int nodec, char *nodes[])
{
    node_t head;
    if (nodec < 1 || nodes == NULL)
        return head;

    node_t *current = &head;
    for (int i = 0; i < nodec; i++)
    {
        current->val = nodes[i];
        current->next = (node_t *)malloc(sizeof(node_t));
        current = current->next;
    }

    return head;
}

void printList(node_t *head)
{
    if (head == NULL)
        return;

    while (head->next != NULL)
    {
        printf("%s\n", head->val);
        head = head->next;
    }
}