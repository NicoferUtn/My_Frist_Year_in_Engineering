#include<iostream>
using namespace std;
float gauss(float x,float& result){
  for(int i=1;i<=x;i++){
    result += i;
  }
    return 0;
}

int main(){
    float x,result = 0;
    cout<<"Dime un numeor para que le aplique la sumatorai de gauss ";cin>>x;
    gauss(x,result);
    cout<<"Tu numero es "<<result;
    return 0;
}