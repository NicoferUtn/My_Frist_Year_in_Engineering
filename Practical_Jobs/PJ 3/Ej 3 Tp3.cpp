#include<iostream>
#include<fstream>

using namespace std;

int main(){
int par = 0, impar = 0;
int sumapar,sumaimp;
ifstream archipar;
archipar.open("archipar.txt");
if ( !archipar ){
    cout<<"\nAnda mal flaco sos tonto ";
}else{
    while (archipar >> par)
    if ((par % 2) == 0)
    {
        cout<<"\n Tu numero es "<<par<<" Y es par";
    }else{
        cout<<"\nNo hay numero pares o no hay numero en el archivo ";
    }
    archipar.close();

    ifstream archiimpar;
    archiimpar.open("archiimpar.txt");
    if (!archiimpar ){
    cout<<"\nAnda mal flaco sos tonto ";
    }else{
    while (archiimpar >> impar)
    if ((impar % 2) -1 == 0)
    {
        cout<<"\n Tu numero es "<<impar<<" Y es impar";
    }else{
        cout<<"\nNo hay numero impares o no hay numero en el archivo ";
    }}}
    return 0;
}

