#include<iostream>
using namespace std;
int main(){
float CP,SP,profit,loss;
cout<<"Enter the CP: "<<endl;
cin>>CP;
cout<<"Enter the SP: "<<endl;
cin>>SP;
if(SP>CP){
    profit=SP-CP;
    cout<<"Profit : "<<profit<<endl;
} 
else{
    loss=CP-SP;
    cout<<"Loss : "<<loss<<endl;
}
return 0;
}

