#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    if(n>99 && n<1000){
        cout<<"The given number is a three digit number";
    }
    else{
         cout<<"The given number is not a three digit number";
    }
    return 0;
}