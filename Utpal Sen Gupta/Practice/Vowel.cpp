#include<iostream>
using namespace std;
int main(){
    char c;
    cout<<"Enter an alphabet:";
    cin>>c;
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        cout<<"Vowel";
    }
    else{
    cout<<"Consonant";
    }
    return 0;
}