#include <iostream>
using namespace;

int main(){
cout<<"Please enter your height(m): ";
float height;
cin>>height;
cout<<"Please enter your weight(kg): ";
float weight;
cin>>weight;
cout<<"Your BMI is: "<<(weight/height/height);
return 0;
}
