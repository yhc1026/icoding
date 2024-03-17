#include <stdio.h>
int main()
{
    int days = 0, st = 0, st1 = 0;
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week(1=Sun, 7=Sat): ");
    scanf("%d", &st1);
    printf("日\t一\t二\t三\t四\t五\t六\n");
    st = st1 - 1;
    if (st == 7)
    {
        int q = 0;
        int left = days - (8 - st);
        int cnt = 0;
        for (cnt = (8 - st); cnt <= days; cnt++)
        {
            printf("%2d\t", cnt);
            q++;
            if ((q % 7) == 0)
            {
                printf("\n");
            }
        }
    }
    else
    {
        int i = 0;
        for (i = 0; i <= (st - 1); i++)
        {
            printf(" \t");
        }
        int t = 0, day = 1;
        for (t = 0; t < (7 - st); t++)
        {
            printf("%2d\t", day);
            day++;
        }
        printf("\n");
        int q = 0;
        int left = days - (8 - st);
        int cnt = 0;
        for (cnt = (8 - st); cnt <= days; cnt++)
        {
            printf("%2d\t", cnt);
            q++;
            if ((q % 7) == 0)
            {
                printf("\n");
            }
        }
    }
}