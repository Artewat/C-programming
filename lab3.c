#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char e[] = "abdldabadsfba";
    for(int i = 0; i < strlen(e); i++)
    {
        if((e[i] == 'a') | (e[i] == 'b'))
        {
                    e[i] = toupper(e[i]);

        }
    }
    printf("%s\n", e);
}