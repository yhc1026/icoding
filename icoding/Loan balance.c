#include <stdio.h>

int main()
{
    float loan = 0, rate = 0, payment = 0, a = 0, b = 0, c = 0;

    printf("Enter amount of loan:");
    scanf("%f", &loan);
    printf("\n");
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("\n");
    printf("Enter monthly payment:");
    scanf("%f", &payment);

    a = (loan - payment);
    a = a + loan * ((rate / 100) / 12);
    printf("Balance remaining after first payment: %.2f\n", a);
    b = (a - payment);
    b = b + a * ((rate / 100) / 12);
    printf("Balance remaining after second payment: %.2f\n", b);
    c = (b - payment);
    c = c + b * ((rate / 100) / 12);
    printf("Balance remaining after third payment: %.2f", c);

    return 0;
}