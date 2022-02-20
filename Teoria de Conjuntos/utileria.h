#ifndef UTILERIA_H
#define UTILERIA_H
#include <string>
#include <vector>
using namespace std;
class Utileria {

public:
	Utileria();
	~Utileria();
	void print();
	void agregar();
	void quitar();
	void crearConjunto();
	void comparar();
	void checkPertenece();
	vector<vector<string>> conjuntos;
	string c;

};

#endif //!UTILERIA_H