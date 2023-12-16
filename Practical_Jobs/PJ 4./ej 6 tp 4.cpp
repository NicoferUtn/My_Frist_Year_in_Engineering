#include<iostream>
#include<fstream>

using namespace std;
void posmin(int v[],int dim,int& min,int& inmin,int& rep){
    min = 0;
    inmin = 0;
    for (int i = 1; i < dim; i++)
    {
        if(v[i] < v[min])
        {min = i;}

        if (v[i]<=v[inmin])
        {inmin = i;}
        
    }
    for (int i = 1; i < dim; i++)
    {
        if (v[i] == v[min])
        {rep++;}
        
    }}

int main(){
    ifstream archi;
    archi.open("datosG04E06-dos.txt");
    if (!archi)
    {
        cout<<"error";
    }
    int min{},inmin{},rep{};
    const int dim {10};
    int v[dim];
    for (int i = 0; i < dim; i++)
    {
        archi>>v[i];
    }
    archi.close();
    posmin(v,dim,min,inmin,rep);
    cout<<"las poosiciones de el menor numero son "<<min<<" "<<inmin<<endl<<"el menor numero es "<<v[min]<<endl;
    cout<<"se repite un total de "<<rep;
    return 0;
    }