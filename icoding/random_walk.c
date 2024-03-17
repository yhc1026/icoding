#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i = 0, j = 0;
    char arr[11][11] = {'.'};
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            arr[i][j] = '.';
        }
    }

    i = j = 0;
    int t = 0;
    int n = 0;
    int m = 0;
    arr[0][0] = 'A';
    for (t = 0; t < 26; t++)
    {
        srand((unsigned)time(NULL));
        n = rand();
        m = n % 4;

        if (i == 0 && j == 0)
        {
            if (m == 0 || m == 1 || m == 3)
            {
                i++;
            }
            if (m == 2)
            {
                j++;
            }
            continue;
        }

        if (i == 0 && j == 10)
        {
            if (m == 0 || m == 1 || m == 2)
            {
                i++;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        if (i == 10 && j == 0)
        {
            if (m == 1 || m == 0 || m == 3)
            {
                i--;
            }
            if (m == 2)
            {
                j++;
            }
            continue;
        }

        if (i == 10 && j == 10)
        {
            if (m == 1 || m == 2 || m == 0)
            {
                i--;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        if (i == 0 && j != 0)
        {
            if (m == 0 || m == 1)
            {
                i++;
            }
            if (m == 2)
            {
                j++;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        if (j == 0 && i != 0)
        {
            if (m == 0 || m == 3)
            {
                i++;
            }
            if (m == 1)
            {
                i--;
            }
            if (m == 2)
            {
                j++;
            }
            continue;
        }

        if (i == 10 && j != 10)
        {
            if (m == 1 || m == 0)
            {
                i--;
            }
            if (m == 2)
            {
                j++;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        if (j == 10 && i != 10)
        {
            if (m == 0 || m == 2)
            {
                i++;
            }
            if (m == 1)
            {
                i--;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        if (i != 0 && i != 10 && j != 10 && j != 0)
        {
            if (m == 0)
            {
                i++;
            }
            if (m == 1)
            {
                i--;
            }
            if (m == 2)
            {
                j++;
            }
            if (m == 3)
            {
                j--;
            }
            continue;
        }

        arr[i][j] = 'B' + t;
    }

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}