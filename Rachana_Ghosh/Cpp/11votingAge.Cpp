#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter the age: "<<endl;
    cin>>age;
    if(age>=18){
        cout<<"Can Vote"<<endl;
    }
    else{
        cout<<"Cannot Vote"<<endl;
    }
    return 0;
}