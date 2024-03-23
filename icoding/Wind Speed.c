#include <stdio.h>
// this is the demo version
int main()
{
    int v = 0;
    printf("Enter a wind speed: ");
    scanf("%d", &v);
    if (v < 1)
    {
        printf("Calm");
    }
    else if (v >= 1 && v <= 3)
    {
        printf("Light air");
    }
    else if (v >= 4 && v <= 27)
    {
        printf("Breeze");
    }
    else if (v >= 28 && v <= 47)
    {
        printf("Gale");
    }
    else if (v >= 48 && v <= 63)
    {
        printf("Storm");
    }
    else if (v >= 63)
    {
        printf("Hurricane");
    }
    return 0;
}