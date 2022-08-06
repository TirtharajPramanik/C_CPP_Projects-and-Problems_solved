#include "cmd.h"

void repl();
char *getcmd();
void handlecmd(char *cmd);

void repl()
{
    greet();
    while (LISTEN > 0)
        handlecmd(getcmd());
};

char *getcmd()
{
    fputs("\n cmd:> \t", stdout);
    fgets(CMD, MAX_LIMIT, stdin);
    strtok(CMD, "\n");
    return CMD;
}

void handlecmd(char *cmds)
{
    char *cmd = strtok(cmds, " ");
    char *opt;
    if (cmd != NULL)
        opt = strtok(NULL, " ");

    if (strcmp(cmd, "exit") == 0)
        exitrepl();
    else if (strcmp(cmd, "help") == 0)
        printhelp();
    else if (strcmp(cmd, "lss") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "ls") == 0)
        printlist();
    else if (strcmp(cmd, "ld") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "uld") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "new") == 0)
        newlist();
    else if (strcmp(cmd, "ins") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "psh") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "pop") == 0)
        printf("%s\n", cmd); // TODO
    else if (strcmp(cmd, "rm") == 0)
        printf("%s\n", cmd); // TODO
    else
        printf("[-] cmd not found!\n");
}
