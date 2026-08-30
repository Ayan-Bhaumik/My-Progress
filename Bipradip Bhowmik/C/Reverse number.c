#include<stdio.h>
int main(){
    int arr[5]={2,5,7,8,10};
    printf("Array elements");
    for(int i=0;i<5;i++){
        printf("%d",&arr[i]);
    }
    printf("Array reverse element");
    for(int i=4;i>=0;i--){
        printf("%d",arr[i]);
    }
    return 0;
}