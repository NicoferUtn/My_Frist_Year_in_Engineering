#include<iostream>

using namespace std;
int main(){
    int a{};
    const int dim = 10;
    int v[dim];
    for (int j = 0; j < dim; j++)
    {
        cout<<"Ingrese 10 numeros ";cin>>v[j]; 
         if(v[j]>v[a])
        {
            a=j;
        }
    }    
    cout<<"tu numero maximo es "<<v[a];
    return 0;
}