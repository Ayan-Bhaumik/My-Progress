 #include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int Sum=0;
    while(n!=0){
        if(n%2==0){
            cout<<" "<<endl;
        }
      int ld=n%10;
      n=n/10;
        Sum+=ld;
    }
    cout<<Sum;
}