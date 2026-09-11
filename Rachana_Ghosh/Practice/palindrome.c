#include<stdio.h>
int main(){
    int n,original,reversed=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
    original=n;
    while(n!=0){
    reversed=reversed*10+n%10;
    n/=10;
    }
    if(original==reversed)
    printf("Palindrome\n");
    else
    printf("Not a palindrome.\n");
    return 0;
}