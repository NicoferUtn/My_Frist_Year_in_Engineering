#include <iostream>

using namespace std;

int main (){
    double prom{};
    const int fil {4},col{3};
    double v[fil][col];

    for (int i = 0; i < fil; i++)
    {
        cout<<"Columna "<<i+1<<endl;

        for ( int j = 0; j < col; j++)
        {
            cout<<"Valor "<<j+1<<" : ";
            cin>>v[i][j];
        }
        
    }
    for (int i = 0; i < fil; i++)
    {
        cout<<endl;
        for (int j = 0; j < col; j++)
        {
            cout<<"["<<v[i][j]<<"]";
            prom +=v[i][j];
        }
        
    }
    cout<<"\nel promedio dle vector es "<<prom/12;
    
    




    return 0;

}