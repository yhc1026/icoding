#include <stdio.h>
int main()
{
    char arr[100] = {0};
    scanf("%[^\n]s", arr);
    char c = 0;
    int i = 0;

    for (i = 0; i >= 0 && arr[i] != 0; i++)
    {
        arr[99 - i] = arr[i];
        arr[i] = 0;
    }

    for (i = 0; i <= 99; i++)
    {
        if (arr[i] == 0 && arr[i] != '\n')
        {
            continue;
        }
        else if (arr[i] == '\n')
        {
            break;
        }
        else
        {
            printf("%c", arr[i]);
        }
    }
    return 0;
}
