#include<iostream>
using namespace std;
int main(){
    int base,height,length,breadth,side,area_triangle,area_rectangle,area_square;
    cout<<"Enter the base : "<<endl;
    cin>>base;
    cout<<"Enter the height: "<<endl;
    cin>>height;
    cout<<"Enter the length: "<<endl;
    cin>>length;
    cout<<"Enter the breadth: "<<endl;
    cin>>breadth;
    cout<<"Enter the side: "<<endl;
    cin>>side;
    area_triangle=0.5*base*height;
    cout<<"The area of triangle: "<<area_triangle<<endl;
    area_rectangle=length*breadth;
    cout<<"The area of rectangle: "<<area_rectangle<<endl;
    area_square=side*side;
    cout<<"the area of square: "<<area_square<<endl;
    return 0;
}