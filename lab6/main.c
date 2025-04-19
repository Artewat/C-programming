#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("Names.txt", "r");
    char buffer[100];
    FILE *out = fopen("out.txt", "w");

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        char Sname[100];
        sscanf(buffer, "%s %*s %*s %*d", &Sname);

        if (Sname[0] == 'A')
        {
            fputs(buffer, out);
        }

    }

    fclose(out);
    fclose(file);
}