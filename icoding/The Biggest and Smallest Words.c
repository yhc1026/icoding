#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100][20] = {'\0'};
    char arr1[100][20] = {'\0'};
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        scanf("%s", &arr[i]);
        if (arr[i][3] != '\0' && arr[i][4] == '\0')
        {
            break;
        }
    }
    int t = 0, n = 0;
    for (t = 1, n = 0; t < 100;)
    {
        if (arr[t][0] == '\0')
        {
            break;
        }
        if (arr[n][0] < arr[t][0])
        {
            t++;
        }

        if (arr[n][0] == arr[t][0])
        {
            int u = strcmp(arr[n], arr[t]);
            if (u == -1)
            {
                t++;
                continue;
            }
            if (u == 1)
            {
                n = t;
                t++;
            }
        }

        else
        {
            n = t;
            t++;
        }
    }
    printf("%s", arr[n]);
