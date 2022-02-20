#ifndef METODOSEJERCICIO2_H	
#define METODOSEJERCICIO2_H	
#include <string>
#include <vector>
using namespace std;

class metodosEjercicio2 {

public:
	metodosEjercicio2();
	~metodosEjercicio2();
	void tablaJuego();
	void cargarGrafo();
	void juego();
	vector<string> grafo;
	string ing;
	int** arr;
};
#endif 