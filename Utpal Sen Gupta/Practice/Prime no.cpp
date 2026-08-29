#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter a number:";
    cin>>n;
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            cout<<"Prime";
        }
        else{
            cout<<"Even";
        }
        return 0;
    }
}