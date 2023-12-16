#include <iostream>

using namespace std;
void pedir(int v[],int dim){
    for (int i = 0; i < dim; i++)
    {
        cout<<"valor "<<i+1<<" : ";
        cin>>v[i];
    }
    for (int i = 0; i < dim; i++)
    {
        cout<<"["<<v[i]<<"]";
    }
    cout<<endl;
    
   
}
void acendente(int v[],int dim){
    int aux{};
    for (int i = 0; i < dim; i++)
    {
     for (int j = 0; j < dim; j++)
     {
        if (v[j] > v[j+1])
        {
            aux = v[j];
            v[j]=v[j+1];
            v[j+1] = aux;
        }
    }
}
    for (int i = 0; i < dim; i++)
    {
        cout<<"["<<v[i]<<"]";
    }
    
}

int main (){
    const int dim {10};
    int v[dim];
    pedir(v,dim);
    acendente(v,dim);

    return 0;
}