#include <stdio.h>

typedef struct
{
    char *name;
    int qty;
    char cat;
    float cost;
} Record;

void displayTable(FILE *fp)
{
    char ch;
    int hb = 70;
    printf("\n|\t");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            printf("\t|\n");
            for (; hb > 0; hb--)
                printf("-");
            printf("\n|\t");
        }
        else if (ch == ',')
            printf("\t|\t");
        else
            printf("%c", ch);
    }
}

void showRecords()
{
    printf("\n[+] Showing All Records...\n");
    FILE *fptr = fopen("records.csv", "r");
    if (!fptr)
    {
        printf("[-] No Records Exist!\n");
        fclose(fptr);
        return;
    }
    displayTable(fptr);
    fclose(fptr);
}

void addRecord()
{
    Record rec;
    printf("\n[+] Adding New Record...\n");
    if ((printf("[+] Enter Record Name (String):\t") && scanf(" %[^\n]s", rec.name)) &&
        (printf("[+] Enter Record Quantity (Integer):\t") && scanf(" %d", &rec.qty)) &&
        (printf("[+] Enter Record Category (`A`|`B`|`C`):\t") && scanf(" %c", &rec.cat)) &&
        (printf("[+] Enter Record Cost (Floating Point Number):\t") && scanf(" %f", &rec.cost)))
    {
        FILE *fptr;
        fptr = fopen("records.csv", "r");
        if (!fptr)
        {
            fclose(fptr);
            fptr = fopen("records.csv", "w");
            if (fptr)
            {
                if (fprintf(fptr, "name,qty,cat,cost\n") &&
                    fprintf(fptr, "%s,%d,%c,%f\n", rec.name, rec.qty, rec.cat, rec.cost))
                    printf("\n[+] New Record <%s> Created!\n", rec.name);
                fclose(fptr);
                exit(0);
            }
        }
        else
        {
            fclose(fptr);
            fptr = fopen("records.csv", "a");
            if (fptr)
            {
                if (fprintf(fptr, "%s,%d,%c,%f\n", rec.name, rec.qty, rec.cat, rec.cost))
                    printf("\n[+] New Record <%s> Created!\n", rec.name);
                fclose(fptr);
                exit(0);
            }
        }
        fclose(fptr);
    }
    printf("\n[-] Could Not Create New Record!\n");
}

void controlExit()
{
    printf("\n[+] Exiting...\n");
}