#include<iostream>
#include<string>
#include "triangle.h"
using namespace std;
// class triangle: public Shape
// {
//  virtual std::string label();
//     virtual void selected();
// };
int main(){
  triangle obj1;
  // double base,height,area;
  cout<<"Enter the base of the traingle:";
  cin>>obj1.base;
  cout<<"Enter the height of the traingle:";
  cin>>obj1.height;
  obj1.area= (obj1.base*obj1.height)*0.5;
  cout<<"The area of the triangle is:"<<obj1.area;
  return 0;
}