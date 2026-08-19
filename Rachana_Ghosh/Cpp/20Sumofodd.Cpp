#include<iostream>
using namespace std;
int main(){
    int n;
    int oddSum=0;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            oddSum+=i;
        }
    }
    cout<<"Odd Sum="<<oddSum<<endl;
    return 0;
}