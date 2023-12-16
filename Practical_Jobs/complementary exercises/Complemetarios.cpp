#include<iostream>

using namespace std;

int main(){
// Primera parte del ejercicio
    int dim{};
    cout<<"Que dimencion queres que sea el vector(empezando desde 0): ";
    cin>>dim;
    const int dimv {dim};
    int v[dimv]{};
    for (int i {}; i <= dimv; i++)
    {
        cout<<"Valor "<< i <<": ";
        cin>>v[dimv - i];
    }
     for (int i {}; i <= dimv; i++)
    {
        cout<<v[i]<<" ";
    }
cout<<endl;
// Segunda parte del ejercicio
    const int fila{2},columna{2};
    int matriz[fila][columna]{};

    for (int i = 0; i < fila; i++)
    {
        cout<<"fila "<<i+1<<": "<<endl;
        for (int j = 0; j < columna; j++)
        {
            cout<<"Columna "<<j+1<<": ";
            cin>>matriz[i][j];
        }
        
    }
    
      for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
           cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<endl;
    }
        for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < i; j++)
        {
          swap(matriz[i][j],matriz[j][i]);
        }
        
    }

cout<<endl;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
           cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0;
}