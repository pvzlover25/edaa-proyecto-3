#include "FM_Index.cpp"

//Compilacion: g++ -std=c++11 -O3 -DNDEBUG -I ~/include -L ~/lib main.cpp -o main -lsdsl -ldivsufsort -ldivsufsort64
//Ejecucion: ./main nombreArchivo1 nombreArchivo2 nombreArchivo3 ...

const char nl='\n';

int main(int argc, char** argv){
	if(argc<3){
		cout<<"Error. Argumentos insuficientes."<<nl;
		return 1;
	}
	string texto="";
	bool inicio=true;
	for(int i=1;i<argc;i++){
		if(texto.empty()) texto+="$";
		ifstream archivo(argv[i],ifstream::in);
		string linea="",lineaAux="";
		while(getLine(archivo,linea)){
			if(!inicio) texto+=nl;
			texto+=linea;
			inicio=false; 
		}
		inicio=true;
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
