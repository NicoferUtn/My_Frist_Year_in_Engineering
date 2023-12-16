#include<iostream>

using namespace std;

int main(){
    int dif {},a {};
    const int dim {8};
    int v[dim];

     cout << "Ingrese los valores del vector: "<<endl;
    for (int i = 0; i < dim; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> v[i];
        if ( v[i] <= v[i - 1]) {
            cout << "ingresaste mal el valor capo"<<endl;
            i--;
        }}
        int elemto1 {}, elemto2 {};
   for (int j = 8;  0 < j ;  j--)
    {
        dif = v[j] - v[j-1];
        if (dif >= a)
        {
            elemto1 = j+1;
            elemto2 = j;
            a = dif;
        }
       
    } 
    cout<<"La mayor diferencia es de "<<a<<endl;
    cout<<"se encuentra entre el elemtnro "<<elemto1<<" y "<<elemto2;
    
         
    
    
    return 0;
    }
    


