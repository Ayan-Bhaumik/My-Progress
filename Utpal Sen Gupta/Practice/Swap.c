#include<stdio.h>
int main(){
    int a,b,temp,*p,*q;
    printf("Enter the first number:");
    scanf("%d",&a);
    printf("Enter the second number:");
    scanf("%d",&b);
    p=&a;
    q=&b;
    temp=*p;
    *p=*q;
    *q=temp;
    printf("The value of the first number is:%d\n",a);
    printf("The value of the Second number is:%d\n",b);
    return 0;
}