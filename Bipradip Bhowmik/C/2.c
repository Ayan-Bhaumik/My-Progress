#include<stdio.h>
int main(){
    int a;
    printf("Enter the number");
    scanf("%d",&a);
    if(a%2==0){
        printf("the number is even");
    }
    else{
        printf("the number is odd");
    }

   return 0;
}