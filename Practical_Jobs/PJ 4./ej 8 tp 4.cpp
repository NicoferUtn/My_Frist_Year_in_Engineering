#include <iostream>
using namespace std;
int main(){
    const int dim {8};
    int v[dim];

    for ( int i = 0; i < dim; i++)
    {
        cout<<" Valor "<<i+1<<":";
        cin>>v[i];
        for (int  j = 0; j < i; j++)
        {
            if (v[i] == v[j])
            {
                cout<<"ta mal ingresado"<<endl;
                i--;
            }
        }
    }
   for (int i = 0; i < dim; i++)
   {
    cout<<"["<<v[i]<<"]"<<endl;
   }
    return 0;
}