#include<iostream>
#include "FM_Index.h"

//Compilacion: g++ -std=c++11 -O3 -DNDEBUG -I ~/include -L ~/lib main.cpp -o main -lsdsl -ldivsufsort -ldivsufsort64

const char nl='\n';

int main(int argc, char** argv){
	if(argc<3){
		cout<<"Error. Argumentos insuficientes."<<nl;
		return 1;
	}
	string texto="";
	for(int i=1;i<argc;i++){
		if(!texto.empty()) texto+="$";
		texto+=argv[i];
	}
	FM_Index fmi(texto);
	cout<<"Ingresa un patron: ";
	string patron;
	cin>>patron;
	string resultado=fmi.doc_locate(patron);
	if(resultado.empty()) cout<<"El patron no se encuentra en el texto\n";
	else{
		cout<<resultado<<nl;
	}
	cout<<"Funciona :)\n";
	return 0;
}
