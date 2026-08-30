#include<stdio.h>
int main(){
    int m;
    printf("Enter m:");
    scanf("%d",&m);
    if(m>0){
        printf("The given number is positive");
    }
    else{
        printf("The given number is negative");
    }
    return 0;
}