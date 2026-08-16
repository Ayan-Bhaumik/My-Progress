#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    if(n>0){
        cout<<"Positive Value."<<endl;
    }else if(n==0){
        cout<<"Value is Zero."<<endl;
    }
    else{
        cout<<"Negative Value."<<endl;
    }
    return 0;
}