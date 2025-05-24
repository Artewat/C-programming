#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int day2(int _year, int _month, int _day)
{
    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo = localtime(&now);
    timeinfo->tm_year = _year - 1900; 
    timeinfo->tm_mon = _month - 1;    
    timeinfo->tm_mday = _day;
    mktime(timeinfo);
    char s[80];
    strftime(s, 80,"%A %B %Y", timeinfo);
    printf("%s\n", s);
}


int day(int _year, int _month, int _day)
{
    char* dayNames[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int a;
    int y;
    int m;
    int R;
    a = (14 - _month) / 12;
    y = _year - a;
    m = _month + 12 * a - 2;
    R = 7000 + (_day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    printf("The day of the week for %04d-%02d-%02d is %s.\n\n",
           _year, _month, _day, dayNames[R%7]);
    return 0;
}


int month(int _year, int _month)
{
    time_t now;
    struct tm *timeinfo;
    char* monthNames[] = { "January", "February", "March", "April", "May", "June", 
                           "July", "August", "September", "October", "November", "December" };
    time(&now);
    timeinfo = localtime(&now);
    timeinfo->tm_year = _year - 1900; 
    timeinfo->tm_mon = _month - 1;    
    printf("\n                        %s %d\n", monthNames[timeinfo->tm_mon], _year);
    printf("_______________________________\n");
    printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
    printf("_______________________________\n");
    timeinfo->tm_mday = 1;
    mktime(timeinfo);
    for (int j = 0; j < timeinfo->tm_wday; j++) {
        printf("    ");
    }
    int daysInMonth = 31; 
    switch (_month) {
        case 2: 
            if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
                daysInMonth = 29; 
            } else {
                daysInMonth = 28; 
            }
            break;
        case 4: case 6: case 9: case 11: 
            daysInMonth = 30;
            break;
    }
    for (int i = 1; i <= daysInMonth; i++) {
        printf("%4d", i); 
        if ((timeinfo->tm_wday + i) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
 
int year(int _year)
{   
    time_t now;
    struct tm * timeinfo;
    int  m, i, j;
    char* month[] = { "January","February", "March","April", "May","June", 
            "July", "August","September","October", "November","December"};
    time (&now); 
    timeinfo = localtime (&now);
    timeinfo->tm_year = _year-1900; 
    timeinfo->tm_mon = 0;
 
    m =-1;
while(m<12)
{   for(i=1; i<33; i++) 
    {   timeinfo->tm_mday = i;
        mktime (timeinfo); 
 
        if(timeinfo->tm_mon > m) 
        {   printf("\n                        %s\n",month[timeinfo->tm_mon]);
            printf("_______________________________\n");
            printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
            printf("_______________________________\n");
            for(j=0;j<(timeinfo->tm_wday);j++)
                printf("    ");
            m++;
            break;
        }
        if (m==11 && timeinfo->tm_mon ==0) 
        {   m++;
            break;
        }
        
        printf("%4d",timeinfo->tm_mday); 
            
        if(timeinfo->tm_wday==6)
            printf("\n");
    }
}
    return 0;
}
void parce (char _str[10], int *ye, int *mo, int *da)
{
    if(strlen(_str) > 3)
        sscanf(_str, "%04d.%02d.%02d", ye, mo, da);
}
int main()
{
    char _string[10];
    int y, m, d;
    printf("Введите год, месяц или дату: ");
    scanf("%s", &_string);
    parce(_string, &y, &m, &d);
    switch(strlen(_string))
    {
        case 3:
            time_t mytime = time(NULL);
            struct tm *now = localtime(&mytime);
            printf("Date: %d.%d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
            break;
        case 4:
            year(y);
            break;
        case 7:
            month(y, m);
            break;
        case 10:
            day2(y, m, d);
            break;
    }
}