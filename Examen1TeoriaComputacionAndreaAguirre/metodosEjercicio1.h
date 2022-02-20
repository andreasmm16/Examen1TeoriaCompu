#ifndef METODOSEJERCICIO1_H	
#define METODOSEJERCICIO1_H	
#include <string>
#include <vector>
using namespace std;

class metodosEjercicio1 {

public:
	metodosEjercicio1();
	~metodosEjercicio1();
	void crearGrafo();
	bool validacionV(string);
	bool validacionE(string);
	void printMatrizGrafo();
	void etiquetarVertice();
	vector<vector<string>> grafos;
	string c;
	string grafC;
	int tmp;

};
#endif 


