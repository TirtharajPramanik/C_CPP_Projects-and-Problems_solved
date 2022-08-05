#include <stdbool.h>
#include <string.h>
#include "linked.h"

#define MAX_LIMIT 20

char cmd[MAX_LIMIT];
bool listen = true;
node_t list;

void greet();
char *getcmd();
void handle_cmd(char *cmd);
void repl();

void greet()
{
    char *nodes[] = {"hello",
                     "bye",
                     "Congrats!"};

    list = createList(3, nodes);
    printf("[*] Awesome, REPL!\n\n");
}

char *getcmd()
{
    fputs(" cmd:> \t", stdout);
    fgets(cmd, MAX_LIMIT, stdin);
    strtok(cmd, "\n");
    return cmd;
}

void handlecmd(char *cmd)
{
    if (!strcmp(cmd, "ls"))
        printList(&list);
    else
    {
        printf("[-] Exiting...\n");
        listen = false;
    }
}

void repl()
{
    greet();
    while (listen)
    {
        handlecmd(getcmd());
    }
};