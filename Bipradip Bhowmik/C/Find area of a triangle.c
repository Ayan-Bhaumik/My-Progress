#include<stdio.h>
int main(){
    
    float base,height,area;
    printf("enter the base of triangle:");
    sacanf("%f",&base);
    printf("enter the height of triangle:");
    scanf("%f",&height);
    area= base*height/2;
    printf("area of triangle is %f",area);
    return 0;
}