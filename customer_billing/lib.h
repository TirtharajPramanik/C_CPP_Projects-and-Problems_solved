#include <stdlib.h>
#include "control.h"

void showOptions()
{
    printf("[1]:\tShow All Records\n");
    printf("[2]:\tAdd New Record\n");
    printf("[3]:\tExit\n");
}

char getInput()
{
    showOptions();
    char cmd;
    printf("Enter:\t");
    if (scanf(" %c", &cmd))
        return cmd;
    return '0';
}

int showJob(char cmd)
{
    switch (cmd)
    {
    case '1':
        showRecords();
        break;
    case '2':
        addRecord();
        break;
    case '3':
        controlExit();
        break;
    default:
        return 0;
    }
    return 1;
}

void getcmd(int tries)
{
    if (tries < 1 || tries > 10)
        tries = 3;
    char cmd;
    for (; tries > 0; tries--)
    {
        cmd = getInput();
        if (showJob(cmd))
            break;
        printf("Error!\tRetry!!\n\n");
    }
}