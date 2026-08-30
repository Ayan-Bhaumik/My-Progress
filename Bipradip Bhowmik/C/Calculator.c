#include<stdio.h>
int main (){
     double num1,num2;
     char op;
     printf("enter the first number ");
     scanf("%lf",&num1);
     printf("enter the second number ");
     scanf("%lf",&num2);
     printf("enter the operator (+,-,*,/): ");
     scanf(" %c",&op);
     switch(op){

    case '+':
    printf("sum=%lf",num1+num2);
    break;
    case '-':
    printf("sub=%lf",num1-num2);
    break;
    case '*':
    printf("mul=%lf",num1*num2);
    break;
    case '/':
    printf("div=%lf",num1/num2);
    break;
    default:
    printf("invalid operator");

     }
     return 0;
    

}