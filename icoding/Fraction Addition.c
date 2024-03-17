#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    printf("Enter two fractions:");
    scanf("%d/%d+%d/%d", &a, &b, &c, &d);
    e = d * a + b * c;
    f = b * d;
    printf("%d/%d", e, f);
    return 0;
}