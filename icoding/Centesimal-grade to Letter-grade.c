#include <stdio.h>
int main()
{
    int grade = 0;
    printf("Enter numerial grade: ");
    scanf("%d", &grade);
    if (grade < 0 || grade > 100)
    {
        printf("Error, grade must be between 0 and 100.");
    }
    else
    {
        grade /= 10;
        switch (grade)
        {
        case (9):
        case (10):
        {
            printf("Letter grade: A");
            break;
        }
        case (8):
        {
            printf("Letter grade:B");
            break;
        }
        case (7):
        {
            printf("Letter grade:C");
            break;
        }
        case (6):
        {
            printf("Letter grade:D");
            break;
        }
        default:
        {
            printf("Letter grade:F");
            break;
        }
        }
    }

    return 0;
}