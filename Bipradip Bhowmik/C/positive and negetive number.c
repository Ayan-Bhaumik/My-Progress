#include<stdio.h>
int main (){
    int a;
    printf("Enter the first number ");
    scanf("%d", &a);
    if(a>0){
        printf("The number is positive");
    }
    else{
        printf("The number is negative");
    }
    return 0;
}