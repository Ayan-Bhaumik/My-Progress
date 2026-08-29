#include<iostream>
using namespace std;
int main(){
    int n,i;
    printf("Enter a number:");
   > scanf("%d",&n);
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            printf("Prime");
        }
        else{
            printf("Even");
        }
        return 0;
    }
}