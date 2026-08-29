#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the first number:");
    scanf("%d",&a);
    printf("Enter the Second number:");
    scanf("%d",&b);
    int*p1=&a;
    int*p2=&b;
    printf("prod:%d\n",*p1 * *p2);
    return 0;
}