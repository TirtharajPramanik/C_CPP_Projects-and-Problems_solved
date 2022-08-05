#include <stdbool.h>
#include <string.h>
#include "linked.h"

#define MAX_LIMIT 20

char CMD[MAX_LIMIT];
bool LISTEN = true;
node_t LIST;

node_t COMMANDS;
char *CMDS[] = {"ls",
                "psh",
                "ins",
                "pop",
                "rm",
                "new"};

void greet();
char *getcmd();
void handle_cmd(char *cmd);
void repl();

void greet()
{
    COMMANDS = createList(6, CMDS);
    printf("[*] Awesome, REPL!\n");
    printf("[*] Type `exit` to Quit Sesson!\n");
    printf("[*] Type `help` to List Commands!\n\n");
}

char *getcmd()
{
    fputs(" cmd:> \t", stdout);
    fgets(CMD, MAX_LIMIT, stdin);
    strtok(CMD, "\n");
    return CMD;
}

void handlecmd(char *cmd)
{
    if (strcmp(cmd, "exit") == 0)
    {
        LISTEN = false;
        printf("[*] Exiting...\n");
    }
    else if (strcmp(cmd, "help") == 0)
        printList(&COMMANDS);
    else if (strcmp(cmd, "ls") == 0)
    {
        if (LIST.val == NULL)
            printf("[*] Create New List with `new` cmd\n");
        else
            printList(&LIST);
    }
    else
        printf("[-] cmd not found!\n");
}

void repl()
{
    greet();
    while (LISTEN)
    {
        handlecmd(getcmd());
    }
};