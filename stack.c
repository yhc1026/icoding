
#include <stdio.h>
#include <stdlib.h>
// 栈 后缀表达式计算
//
//  请使用已定义好的栈完成后缀表达式计算：
//(1)如果是操作数，直接入栈
//(2)如果是操作符op，连续出栈两次，得到操作数x 和 y, 计算 x op y，并将结果入栈。
//
//  后缀表达式示例如下：
//  9  3  1 - 3 * +10  2 / +
//  13  445 + 51 / 6 -
//  操作数、操作符之间由空格隔开，操作符有 + ， - ，*, / , % 共 5 种符号，所有操作数都为整型。
//
//  栈的定义如下：
//
#define Stack_Size 50
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;

void init_stack(Stack *S)
{
    S->top = -1;
}

int Pop(Stack *S, ElemType *x)
{
    if (S->top == -1) /*栈为空*/
        return (FALSE);
    else
    {
        *x = S->elem[S->top];
        S->top--; /* 修改栈顶指针 */
        return (TRUE);
    }
}

int Push(Stack *S, ElemType x)
{
    if (S->top == Stack_Size - 1)
        return (FALSE); /*栈已满*/
    S->top++;
    S->elem[S->top] = x;
    return (TRUE);
}

int compute_reverse_polish_notation(char *str)
{
    Stack st;
    init_stack(&st);
    int i = (int)strlen(str);
    char x = 0;
    int t = 0;
    int num = 0;
    while (t < i)
    {
        x = str[t];
        if (x == ' ')
        {
            t++;
            continue;
        }
        if (x >= 48 && x <= 57)
        {
            while (i < t && str[t] >= 48 && str[t] <= 57)
            {
                x = 10 * x + (str[t] - '0');
                t++;
            }
            push(&st, x);
            x = 0;
        }
        else
        {
            int *a = NULL;
            pop(&st, a);
            int *b = NULL;
            pop(&st, b);
            switch (str[t])
            {
            case '+':
            {
                num = *a + *b;
                break;
            }
            case '-':
            {
                num = *a - *b;
                break;
            }
            case '*':
            {
                num = *a * *b;
                break;
            }
            case '/':
            {
                num = *a / *b;
                break;
            }
            case '%':
            {
                num = *a % *b;
                break;
            }
            }
            push(&st, num);

            t++;
        }
    }
    int *sum = NULL;
    pop(&st, sum);
    return *sum;
}
