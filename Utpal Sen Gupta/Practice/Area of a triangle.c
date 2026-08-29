#include<stdio.h>
int main(){
    int b,h,Area;
    printf("Enter the base of the triangle:");
    scanf("%d",&b);
    printf("Enter the height of the triangle:");
    scanf("%d",&h);
    Area=b*h/2;
    printf("%d\n",Area);
    return 0;
}