#include <stdio.h>
int main()
{
    int hour = 0, min = 0;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    if (hour > 12)
    {
        hour -= 12;
        if (min < 10)
        {
            printf("Equivalent 12-hour time: %d:0%dPM", hour, min);
        }
        else
        {
            printf("Equivalent 12-hour time: %d:%dPM", hour, min);
        }
    }
    else if (hour == 12)
    {
        if (min < 10)
        {
            printf("Equivalent 12-hour time: %d:0%dPM", hour, min);
        }
        else
        {
            printf("Equivalent 12-hour time: %d:%dPM", hour, min);
        }
    }
    else if (hour == 0)
    {
        hour += 12;
        if (min < 10)
        {
            printf("Equivalent 12-hour time: %d:0%dAM", hour, min);
        }
        else
        {
            printf("Equivalent 12-hour time: %d:%dAM", hour, min);
        }
    }
    else
    {
        if (min < 10)
        {
            printf("Equivalent 12-hour time: %d:0%dAM", hour, min);
        }
        else
        {
            printf("Equivalent 12-hour time: %d:%dAM", hour, min);
        }
    }
    return 0;
}