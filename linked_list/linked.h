#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *val;
    struct node *next;
} node_t;

node_t createList(int nodec, char *nodes[]);
int printList(node_t *head);

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

int printList(node_t *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    printf("[+] { ");

    while (head->next != NULL)
    {
        printf("%s, ", head->val);
        head = head->next;
        count++;
        if (count % 10 == 0)
            printf("\n\t");
    };

    printf(" }\n");
    printf("[+] Count:\t%d\n", count);
    return count;
}