//Given an integer array and a target value, return the indices of two different elements whose sum equals the target. Assume exactly one valid pair exists.
#include<iostream>
using namespace std;
int  main(){
    int arr[5]={1,2,3,4,5};
    int target=7;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]+arr[j]==target){
            cout<<"Indices= "<<i<<j<<endl;
            }
        }
    } 
return 0;
}