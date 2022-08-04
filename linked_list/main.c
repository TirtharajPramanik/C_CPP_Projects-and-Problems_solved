#include "linked.h"

int main(int argc, char *argv[])
{
    node_t list;
    if (argc > 1)
    {
        char *nodes[argc - 1];
        for (int i = 1; i < argc; i++)
            nodes[i - 1] = argv[i];
        list = createList(argc - 1, nodes);
    }
    else
    {
        char *nodes[] = {"hello",
                         "bye",
                         "Congrats!"};
        list = createList(3, nodes);
    };
    printList(&list);
    return 0;
}