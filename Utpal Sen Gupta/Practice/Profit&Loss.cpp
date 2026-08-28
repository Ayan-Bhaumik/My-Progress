#include<iostream>
using namespace std;
int main(){
    int CP;
    cout<<"Enter the CP:";
    cin>>CP;
    int SP;
    cout<<"Enter the SP:";
    cin>>SP;

        if(CP<SP){
          cout<<"It's a Profit..."<<endl;
          cout<<"The profit is:"<<SP-CP;
        }

        else if(CP>SP){
            cout<<"It's a loss..."<<endl;
            cout<<"The Loss is:"<<CP-SP;
            }
      else{
        cout<<"It's a no profit and no loss";
        }

}