#include <stdio.h>
int main()
{
    int num = 0;
    float tax = 0;
    printf("Enter an amount:");
    scanf("%d", &num);
    tax = 1.05 * num;
    printf("with tax added:%.2f", tax);
    return 0;
}