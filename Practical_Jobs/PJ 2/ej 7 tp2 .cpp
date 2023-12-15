#include<iostream>
using namespace std;
int Fibonacci(int x,int& result,int& a,int& b,int& c){
        for (int i = 1; i<x; i++)
  {
    result = b + c;
    b=c;
    c=result;
  } 
    return result+1/x;
}
int main(){
    int x,result = 0,a=1,b=0,c=1;
    cout<<"Decime un numero para la sucesion ";cin>>x; 
    Fibonacci(x,result,a,b,c);
    cout<<"Tu numero es "<<result;


    return 0;
}
