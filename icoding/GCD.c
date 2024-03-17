#include <stdio.h>
int main()
{
    int m = 0, n = 0;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    if (m == 0)
    {
        printf("Greatest common divisor: %d", n);
    }

    for (; n != 0;)
    {
        int t = n;
        n = m % n;
        m = t;
    }
    printf("Greatest common divisor:%d", m);
    return 0;
}