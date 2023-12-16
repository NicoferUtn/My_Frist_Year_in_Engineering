#include<iostream>

using namespace std;

int pos(int v[],int dim,int& max,int& med){
    max = 0;
    med = 0;
    for (int i = 1; i < dim; i++)
    {
        if (v[i]>v[max])
        {
            med = max;
            max = i;  
        }else if (v[i] > v[med])
        {
            med = i;
        }
        
    } 
        return 0;
}


int main(){
    const int dim {10};
    int v[dim]{6,1,3,7,9,4,10,2,8,5};
    int max{},med{};
    pos(v,dim,max,med);
    cout<<"el numero mayor es "<<v[max]<<" y el que le sigue es "<<v[med]<<endl;


    return 0;
}