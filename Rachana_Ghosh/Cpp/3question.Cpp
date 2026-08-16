#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the value of a: "<<endl;
    cin>>a;
    if(a%2==0){
        cout<<"Even number."<<endl;
    }else{
        cout<<"Odd number."<<endl;
    }
    return 0;
}