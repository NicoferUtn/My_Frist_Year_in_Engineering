#include <iostream>

using namespace std;


int main(){
    const int dim {8};
    int v[dim]{8,4,3,5,7,1,0,10};
    string equi[dim]{"a","b","c","d","e","f","g","h"};

int aux{};
string axun;
 for (int i = 0; i < dim; i++)
 {
    for (int j = 0; j < dim; j++)
    {
        if (v[j]<v[j+1])
        {
           aux = v[j];
           v[j]=v[j+1];
           v[j+1]=aux;

            axun = equi[j];
           equi[j]=equi[j+1];
           equi[j+1]=axun;
        }
        
    }
    
 }
 for (int i = 0; i < dim; i++)
 {
    cout<<"["<<equi[i]<<"||"<<v[i]<<"]"<<endl;
 }
 
 
    return 0;
}