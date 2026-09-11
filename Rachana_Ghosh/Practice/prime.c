#include<stdio.h>
int main(){
    int n,isPrime=1;
    printf("Enter the value of n:");
    scanf("%d",&n);
    if(n<=1)
    isPrime=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            isPrime=0;
            break;
        }
    }
    printf(isPrime?"%d is  prime.\n":"%d is not  prime.\n",n );
return 0;

}