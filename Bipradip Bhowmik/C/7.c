#include<stdio.h>
int main (){
    int a,b,temp;
    printf("Enter the first number ");
    scanf("%d",&a);
    printf("Enter the second number");
    scanf("%d",&b);
    temp=a;
    a=b;
    b=temp;
    printf("After swapping: a=%d, b=%d", a, b);
    return 0;
}