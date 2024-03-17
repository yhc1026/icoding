#include <stdio.h>
int main()
{
    int num = 0, a = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (a = 2; a * a < num; a += 2)
    {
        printf("%d\n", a * a);
    }
    return 0;
}