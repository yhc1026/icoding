#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = '0';
    float num = 0, sum = 0;
    printf("Enter an expression: ");
    scanf("%f", &num);
    sum += num;
    for (; (c = getchar()) != '\n';)
    {
        scanf("%f", &num);
        if (c == '+')
        {
            sum += num;
        }
        if (c == '-')
        {
            sum -= num;
        }
        if (c == '*')
        {
            sum *= num;
        }
        if (c == '/')
        {
            sum /= num;
        }
    }
    printf("%.2f", sum);
    return 0;
}