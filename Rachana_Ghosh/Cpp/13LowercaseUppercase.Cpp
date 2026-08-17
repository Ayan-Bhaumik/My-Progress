#include<iostream> 
using namespace std;
int main(){
    char ch;
    cout<<"Enter the character:"<<endl;
    cin>>ch;
    if(ch>='a' && ch<='z'){
        cout<<"Lower case."<<endl;
    }else{
        cout<<"Uppercase."<<endl;
    }
    return 0;
}