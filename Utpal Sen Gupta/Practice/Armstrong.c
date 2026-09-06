#include<stdio.h>
int main(){
    int n,original,remainder,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    original=n;
    while(n!=0){
    remainder=n%10;
    sum=sum + remainder * remainder * remainder;
    n=n/10;
    }
    if(sum==original){
        printf("The given number is an armstrong%d\n",original);
    }else{
        printf("The given number is not an armstrong%d\n",original);
    }
    return 0;
}