#include <stdio.h>

typedef struct
{
    char *name;
    int qty;
    char cat;
    float cost;
} Record;

void showRecords()
{
    printf("\n[+] Showing All Records...\n");
}

void addRecord()
{
    printf("\n[+] Adding New Record...\n");
    Record rec;
    if ((printf("[+] Enter Record Name (String):\t") && scanf(" %s", rec.name)) &&
        (printf("[+] Enter Record Quantity (Integer):\t") && scanf(" %d", &rec.qty)) &&
        (printf("[+] Enter Record Category (`A`|`B`|`C`):\t") && scanf(" %c", &rec.cat)) &&
        (printf("[+] Enter Record Cost (Floating Point Number):\t") && scanf(" %f", &rec.cost)))
    {
        FILE *fp;
        fp = fopen("records.csv", "r");
        if (!fp)
        {
            fclose(fp);
            fp = fopen("records.csv", "w");
            if (fp)
            {
                if (fprintf(fp, "name,qty,cat,cost\n") &&
                    fprintf(fp, "%s,%d,%c,%f\n", rec.name, rec.qty, rec.cat, rec.cost))
                    printf("\n[+] New Record <%s> Created!\n", rec.name);
                fclose(fp);
                exit(0);
            }
        }
        else
        {
            fclose(fp);
            fp = fopen("records.csv", "a");
            if (fp)
            {
                if (fprintf(fp, "%s,%d,%c,%f\n", rec.name, rec.qty, rec.cat, rec.cost))
                    printf("\n[+] New Record <%s> Created!\n", rec.name);
                fclose(fp);
                exit(0);
            }
        }
        fclose(fp);
    }
    printf("\n[-] Could Not Create New Record!\n");
}

void controlExit()
{
    printf("\n[+] Exiting...\n");
}