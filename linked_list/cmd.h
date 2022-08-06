#include <string.h>
#include "linked.h"

#define MAX_LIMIT 60

char CMD[MAX_LIMIT];
int8_t LISTEN = 1;
node_t LIST;

char *CMDS[] = {"ld",
                "uld",
                "ls",
                "lss",
                "psh",
                "ins",
                "pop",
                "rm",
                "new"};

void greet();
void printhelp();
void exitrepl();
void printlist();
void newlist();

void greet()
{
    printf("[*] Awesome, REPL!\n");
    printf("[*] Type `exit` to Quit Sesson!\n");
    printf("[*] Type `help` to List Commands!\n");
}

void printhelp()
{
    FILE *fptr = fopen("help.txt", "r");
    if (fptr == NULL)
    {
        fclose(fptr);
        greet();
        return;
    }

    char str[MAX_LIMIT];
    while (fgets(str, MAX_LIMIT, fptr) != NULL)
        fputs(str, stdout);
    fputs("\n", stdout);
    fclose(fptr);
}

void exitrepl()
{
    LISTEN = 0;
    printf("[*] Exiting...\n");
}

void printlist()
{
    if (LIST.val == NULL)
    {
        printf("[*] Load a List with `ld` cmd\n");
        printf("[*] Create New List with `new` cmd\n");
        printf("[*] See `help` for more info\n");
    }
    else
        printList(&LIST);
}

void newlist()
{
    LIST = createList(9, CMDS);
    printf("[+] Created new List `%s`\n", "ns");
}
