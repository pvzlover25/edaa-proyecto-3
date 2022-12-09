#ifndef FM_INDEX_H
#define FM_INDEX_H
#include<string>
#include<vector>
#include<utility>
#include<sdsl/suffix_arrays.hpp>

using namespace std;
using namespace sdsl;
typedef pair<int,int> rango;

class FM_Index{
private:
	csa_wt<wt_int<>> fmi;
	vector<rango> docs;
	string txt;
public:
	FM_Index(string &texto);
	~FM_Index();
	int count(string &patron);
	vector<int> posiciones(string& patron);
	string doc_locate(string &patron);
};
#endif
