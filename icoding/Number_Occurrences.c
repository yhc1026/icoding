#include <stdio.h>
int main()
{
    int arr1[100] = {0}, num, t, i, arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d", &num);
    if (num == 0)
    {
        arr2[0] = 1;
    }

    while (num != 0)
    {
        t = num % 10;
        num /= 10;
        arr1[i] = t;
        i++;
    }

    int u = 0, n = 0;
    for (n = 0; n < i; n++)
    {
        u = arr1[n];
        arr2[u]++;
    }

    int z = 0;
    printf("Digits:");
    for (z = 0; z < 10; z++)
    {
        printf("%d ", z);
    }
    printf("\n");
    printf("Occurrences:");
    int l = 0;
    for (l = 0; l < 10; l++)
    {
        printf("%d ", arr2[l]);
    }
    return 0;
}