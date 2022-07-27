int isNumber(char number[]);

int isNumber(char number[])
{
    int i = 0;
    // checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        if (number[i] > '9' || number[i] < '0')
            return 0;
    }
    return 1;
}
