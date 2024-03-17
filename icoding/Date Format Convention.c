#include <stdio.h>
int main()
{
    int date = 0, month = 0, year = 0;
    printf("Enter a date:");
    scanf("%d/%d/%d", &month, &date, &year);
    if (date < 10 && month >= 10)
    {
        printf("You entered the date %d%d0%d", year, month, date);
    }
    else if (month < 10 && date >= 10)
    {
        printf("You entered the date %d0%d%d", year, month, date);
    }
    else if (date < 10 && month < 10)
    {
        printf("You entered the date %d0%d0%d", year, month, date);
    }
    else
    {
        printf("You entered the date %d%d%d", year, month, date);
    }
    return 0;
}
