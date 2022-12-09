#ifndef FM_INDEX_CPP
#define FM_INDEX_CPP
#include "FM_Index.h"

FM_Index::FM_Index(string &texto){
/*Nota: Se asume que todos los documentos en el string contienen
   al menos un caracter */
	construct_im(fmi,texto,1);
	int posInicial=0;
	for(int i=0;i<texto.length();i++){
		if(texto[i]=='$'){
			rango r(posInicial,i-1);
			docs.push_back(r);
			posInicial=i+1;
		}
	}
	rango rg(posInicial,texto.length()-1);
	docs.push_back(rg);
	txt=texto;
}

FM_Index::~FM_Index(){}

int FM_Index::count(string &patron){
	return sdsl::count(fmi,patron.begin(),patron.end());
}

vector<int> FM_Index::posiciones(string &patron){
	auto locations=sdsl::locate(fmi,patron.begin(),patron.end());
	sort(locations.begin(),locations.end());
	vector<int> ret;
	for(auto it=locations.begin();it!=locations.end();it++){
		ret.push_back(*it);
	}
	return ret;
}

string FM_Index::doc_locate(string &patron){
	string ret="";
	vector<int> locations=posiciones(patron);
	vector<rango> rangos;
	int indice=0;
	for(int i=0;i<locations.size();i++){
		int l=locations[i];
		while(l>docs[indice].second && indice<docs.size()){
			indice++;
		}
		if(indice==docs.size()) break;
		rangos.push_back(docs[indice]);
	}
	for(int i=0;i<rangos.size();i++){
		if(!ret.empty()) ret+="$";
		rango r=rangos[i];
		string sub=txt.substr(r.first,r.second-r.first+1);
		ret+=sub;
	}
	return ret;
}
#endif
