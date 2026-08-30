#include<stdio.h>
int main(){
    int n,i,sum=0;
    int a[100];
    printf("entre the nummber of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    printf("sum:%d",sum);
    return 0;
}