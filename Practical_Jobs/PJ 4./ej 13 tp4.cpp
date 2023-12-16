#include<iostream>

using namespace std;

int main(){
    int minf{},minc{};
    const int fil{5},col{4};
    int v[fil][col];

    for (int i = 0; i < fil; i++)
    {   
        cout<<"columnas "<<i+1<<endl;
        for (int j = 0; j < col; j++)
        {
            cout<<"valor "<<j+1<<" : ";
            cin>>v[i][j];
        }
        
    }
        for (int i = 0; i < fil; i++)
    {
        cout<<endl;
        for (int j = 0; j < col; j++)
        {
            cout<<"["<<v[i][j]<<"]";
        }
        
    }

    
    for (int i = 0; i < fil; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (v[i][j]<v[minf][minc])
            {
                minf = i;
                minc = j;
            }
            
        }
        
    }
    cout<<"\nel menor numero es "<<v[minf][minc]<<" en la fila "<<minf<<" en la columna "<<minc;




    return 0;
}