#include <stdio.h>
int main()
{
    printf("Enter a phone number: ");
    char c = '0';
    while ((c = getchar()) != '\n')
    {
        if (c == 'A' || c == 'B' || c == 'C')
        {
            printf("2");
        }
        if (c == 'D' || c == 'D' || c == 'F')
        {
            printf("3");
        }
        if (c == 'G' || c == 'H' || c == 'I')
        {
            printf("4");
        }
        if (c == 'J' || c == 'K' || c == 'L')
        {
            printf("5");
        }
        if (c == 'M' || c == 'N' || c == 'O')
        {
            printf("6");
        }
        if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
        {
            printf("7");
        }
        if (c == 'T' || c == 'U' || c == 'V')
        {
            printf("8");
        }
        if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
        {
            printf("9");
        }
        if (c == '-')
        {
            printf("-");
        }
    }
    return 0;
}