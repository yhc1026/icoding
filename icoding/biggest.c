#include <stdio.h>
#include <string.h>
void swap();

int main()
{
    char arr[100][100] = {0};
    int i = 4, j = 0;
    for (j = 0; i != 4; j++)
    {
        scanf("%s", &arr[j]);
        i = strlen(arr[j]);
    }
    for (j = 0; arr[0][j] != 0; j++)
    {
        if (arr[0][j] <= arr[0][j + 1])
        {
            swap(arr[0][j], arr[0][j + 1]);
        }
    }
    for (j = 0; arr[0][j] != 0; j++)
    {
        printf("%c", arr[0][j]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}
