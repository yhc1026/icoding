#include <stdio.h>
int main()
{
    int num = 0, twe = 0, ten = 0, fiv = 0, one = 0;
    printf("Enter an amount:");
    scanf("%d", &num);
    twe = num / 20;
    num = num % 20;
    ten = num / 10;
    num = num % 10;
    fiv = num / 5;
    one = num % 5;
    printf("$20 bills:%d\n$10 bills:%d\n$5 bills:%d\n$1 bills:%d\n", twe, ten, fiv, one);
    return 0;
}