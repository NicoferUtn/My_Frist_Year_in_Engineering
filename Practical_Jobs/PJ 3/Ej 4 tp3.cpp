#include<iostream>
#include<fstream>


using namespace std;

int main(){
    ofstream textofin;
    string texto3;
    textofin.open("textofin");
    if (!textofin)
    {
        cout<<"Funca mal el texto 3";
    }else{

    string texto1,tex1;
    ifstream textouno;
    textouno.open("Textouno.txt");
    if( !textouno ){
        cout<<"Sos tondo flaco";
    }else{
        if (textouno>> texto1)
        {
        do{
            textofin<<texto1<<" ";
        }while(textouno >> texto1);
            
        }else{cout<<"No hay texto en el texto 1";}
        
   
    textouno.close();
    }
    string texto2, tex2;
    ifstream textodos;
    textodos.open("textodos.txt");
    if ( !textodos )
    {
        cout<<"Sos tonto";
    }else{
        if (textodos >> texto2)
        {
        do{
            textofin<<texto2<<" ";
        }while (textodos >> texto2);
                
                
        }else{cout<<"No hay texto en el texto 2";}
    textodos.close();
    }
    }
    

    return 0;
}