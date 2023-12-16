#include<iostream>
#include<fstream>

using namespace std;


int main(){
    int a {};
    double  prom {};
    const int dim =7;
    double v[dim] {};
    ifstream archivo;
    archivo.open("datosG04E02.txt");
    if(!archivo){
        cout<<"Sos boludo flaco";
    }else{
    for (int i = 0; i < dim; i++)
    {
        archivo>>v[i];
        if (v[i]>6)
        {
        prom +=v[i];
        cout<<"\n"<<v[i];
        a++;
        } 
    }
    cout<<"Peomedios"<<prom/a;
    archivo.close();
    return 0;
    }}