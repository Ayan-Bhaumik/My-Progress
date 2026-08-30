#include <stdio.h>

int main()
{
    double m, n;
    char op;

    printf("Enter the first number: ");
    scanf("%lf", &m);

    printf("Enter the Second number: ");
    scanf("%lf", &n);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op)
    {
        case '+':
            printf("Result: %.2f\n", m + n);
            break;

        case '-':
            printf("Result: %.2f\n", m - n);
            break;

        case '*':
            printf("Result: %.2f\n", m * n);
            break;

        case '/':
            if(n != 0)
            {
                printf("Result: %.2f\n", m / n);
            }
            else
            {
                printf("Error: Divided by Zero\n");
            }
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}