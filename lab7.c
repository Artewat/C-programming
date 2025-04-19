#include <stdio.h>

struct humen
{

    char Name[100];
    char Sname[100];
    int byear;
    
};
int strcount()
{

    int c = 0;
    char buffer[100];
    FILE *fp = fopen("Names.txt", "r");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) 
    {
        
        c++;

    }

    fclose(fp);

    return(c);
}



int main()
{
    int lines = strcount();

    struct humen Chel1[lines];
    struct humen Chel2[lines];

    int c = 0;
    FILE *file = fopen("Names.txt", "r");
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        
        sscanf(buffer, "%s %s %d", &Chel1[c].Sname, &Chel1[c].Name, &Chel1[c].byear );
        c++;

    }

    for (int i = 0; i < lines; i++)
    {
        printf("%s\n%s\n%d\n\n", Chel1[i].Name, Chel1[i].Sname, Chel1[i].byear);
    }

    printf("--------------------------------------\n");

    c = 0;
    struct humen flag;
    flag.byear = 0;

    for (int j = 0; j < lines; j++)
    {
        
        for (int i = 0; i < lines; i++)
        {

            if(Chel1[i].byear > flag.byear)
            {
                flag = Chel1[i];
                c = i;
            }

        }
        
        Chel1[c].byear = 0;
        Chel2[j] = flag;
        flag.byear = 0;

    }

    for (int i = 0; i < lines; i++)
    {
        printf("%s\n%s\n%d\n\n", Chel2[i].Name, Chel2[i].Sname, Chel2[i].byear);
    }

    fclose(file);
}