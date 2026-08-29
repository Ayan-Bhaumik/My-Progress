#include<stdio.h>
int main(){
    float l,b,Area;
    printf("Enter the length of the rectangle:");
    scanf("%f",&l);
    printf("Enter the breadth of the rectangle:");
    scanf("%f",&b);
    Area=l*b;
    printf("Area of the rectangle is:%f\n",Area);
    return 0;
}