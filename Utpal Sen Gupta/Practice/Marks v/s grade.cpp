#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the respective marks:";
    cin>>m;
    if( m>=90){
        cout<<"Grade A";
    }
    else if(m>=80){
        cout<<"Grade B";
    }
     else if(m>=70){
        cout<<"Grade C";
     }
      else if(m>=60){
        cout<<"Grade D";
      }
       else if(m>=50){
        cout<<"Grade E";
       }
        else if(m>=40){
        cout<<"Aap fail ho gaye!!!";
        }
     return 0;   
}