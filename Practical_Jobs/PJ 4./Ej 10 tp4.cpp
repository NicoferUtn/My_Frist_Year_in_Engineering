#include <iostream>

using namespace std;

int main(){
    const int dim {8};
   
    int v[dim]{8,4,3,5,7,1,0,10};
    int equipos[dim]{1,2,3,4,5,6,7,8};
                        
    
    int aux {};
    for (int i = 0; i < dim -1; i++)
    {
        for (int j = 0; j < dim-1; j++)
        {
            if (v[j] < v[j+1])
            {
                aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            
                aux = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1]= aux;

            }
            
        }
        
    }
    for (int  i = 0; i < dim; i++)
    {
        cout<<"["<<equipos[i]<<"||"<<v[i]<<"]"<<endl;
    }
    
    return 0;
}