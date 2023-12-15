#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string str;
    cout<<"Dime que palabras quieres introducir en el texto ";
    getline(cin,str);
        if (80 >(str.size()))
        {
    ofstream textito;
    textito.open("textito.txt");
        if(!textito){
            cout<<"NO ANDA ";
        }else{
            textito<<str;
        }
        }else{
            cout<<"Te pasaste de las palabaras crack ";
        }
        return 0;
    }

