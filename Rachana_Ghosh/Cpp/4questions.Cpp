#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the year: "<<endl;
    cin>>n;
    if(n%4==0 && n%100!=0 ||n%400==0){
        cout<<"The year is a leap year."<<endl;
    }else{
        cout<<"The year is not a leap year."<<endl;
    }
    return 0;
}
