#include "utileria.h"
#include <iostream>
#include <string.h>

using namespace std;

Utileria::Utileria() {
	c = "";

}

void Utileria::crearConjunto() {
	c = "";
	int tmp = 0;
	vector<string> v1;
a: cout << endl << "CREAR CONJUNTO" << endl << "Ingrese nombre para conjunto:";
	cin >> c;

	if (c == "salir") {
		return;
	}

	for (int x = 0; x < conjuntos.size(); x++)
	{
		if (conjuntos.at(x).at(0) == c) {
			tmp = 1;
		}
	}

	if (tmp == 0) {
		v1.push_back(c);
		conjuntos.push_back(v1);
		cout << "¡Conjunto creado!" << endl;
	}
	else {
		cout << "Conjunto ya existe" << endl;
		tmp = 0;
		goto a;
	}
}

void Utileria::agregar() {
	c = "";
b:	cout << endl << "AGREGAR A CONJUNTO" << endl << "Ingrese nombre de conjunto:";
	cin >> c;
	int tmp=0,num = 0;


	if (c == "salir") {
		return;
	}

	for (int x = 0; x < conjuntos.size(); x++)
	{
		if (conjuntos.at(x).at(0) == c) {
			tmp = 1;
			num = x;
		}
	}

	if (tmp == 0) {
		cout << "Conjunto no existe" << endl;
		goto b;
	}
	else {
	d:cout << "Ingrese número a insertar:";
		cin >> c;
		conjuntos.at(num).push_back(c);
		cout << "¡Número insertado éxitosamente! ¿Desea agregar otro elemento? Ingrese Si o No:";
		cin >> c;
		if (c == "Si") {
			goto d;
		}
		else {
			return;
		}
	}
}

void Utileria::quitar() {
	c = "";
b:	cout << endl << "ELIMINAR DE CONJUNTO" << endl << "Ingrese nombre de conjunto:";
	cin >> c;
	int tmp = 0, num = 0, num2=0;


	if (c == "salir") {
		return;
	}

	for (int x = 0; x < conjuntos.size(); x++)
	{
		if (conjuntos.at(x).at(0) == c) {
			tmp = 1;
			num = x;
		}
	}

	if (tmp == 0) {
		cout << "Conjunto no existe" << endl;
		goto b;
	}
	else {
		tmp = 0;
	d:cout << "Ingrese número a eliminar:";
		cin >> c;


		if (c == "salir") {
			return;
		}

		for (int x = 0; x < conjuntos.at(num).size(); x++) {
			if (conjuntos.at(num).at(x) == c) {
				
				tmp = 1;
			}
		}

		if (tmp == 0) {
			cout << "Número no existente en conjunto" << endl;
			goto d;
		}
		else {
			num2 = conjuntos.at(num).size();
			for (int x = 0; x < num2; x++) {
				if (conjuntos.at(num).at(x) == c) {
					conjuntos.at(num).erase(conjuntos.at(num).begin() + x);
					num2 = conjuntos.at(num).size();
					x = 0;
				}
			}
			
			cout << "¡Número eliminado éxitosamente! ¿Deseas eliminar otro número? Ingresa Si o No:";
			cin >> c;
			if (c == "Si") {
				goto d;
			}
			else {
				return;
			}

		}
		
		
		cin >> c;
		if (c == "Si") {
			goto d;
		}
		else {
			return;
		}
	}
}

void Utileria::comparar() {
	c = "";
	string c2 = "";
	int tmp = 0, num1 = 0,num2=0, dis=0;

a:	cout << endl << "COMPARAR CONJUNTOS" << endl << "Ingrese nombre de conjunto 1:";
	cin >> c;
	if (c == "salir") {
		return;
	}
	for (int x = 0; x < conjuntos.size(); x++)
	{
		if (conjuntos.at(x).at(0) == c) {
			tmp = 1;
			num1 = x;
		}
	}
	if (tmp == 0) {
		cout << "Conjunto no existente" << endl;
		goto a;
	}
	else {
		tmp = 0;
	b:	cout << "Ingrese nombre de conjunto 2:";
		cin >> c;
		for (int x = 0; x < conjuntos.size(); x++)
		{
			if (conjuntos.at(x).at(0) == c) {
				tmp = 1;
				num2 = x;
			}
		}

		if (tmp == 0) {
			cout << "Conjunto no existente" << endl;
			goto b;
		}
		else {
			for (int x = 0; x < conjuntos.at(num1).size()-1; x++) {
				dis = 0;
				c = conjuntos.at(num1).at(x + 1);

				for (int j = 0; j < conjuntos[num2].size(); j++) {
					if (c == conjuntos[num2].at(j)) {
						dis = 1;
					}
				}
				if (dis == 0) {
					cout << "Conjuntos no son equivalentes" << endl;
					goto q;
				}
			}


		}
		cout << "Conjuntos son equivalentes" << endl;
	q:	return;
	}

}

void Utileria::checkPertenece() {
	c = "";
	int tmp = 0, num=0;
a:cout << endl << "VERIFICAR SI PERTENECE" << endl << "Ingrese nombre de conjunto:";
	cin >> c;
	if (c == "salir") {
		return;
	}

	for (int x = 0; x < conjuntos.size(); x++)
	{
		if (conjuntos.at(x).at(0) == c) {
			tmp = 1;
			num = x;
		}
	}
	if (tmp == 0) {
		cout << "Conjunto no existente" << endl;
		goto a;
	}
	else {
		cout << "Ingrese nombre de número a verificar:";
		cin >> c;
		tmp = 0;
		for (int x = 0; x < conjuntos.at(num).size(); x++) {
			if (conjuntos.at(num).at(x) == c) {
				tmp = 1;
			}
		}
		if (tmp == 1) {
			cout << "Si pertenece a conjunto"<<endl;
		}
		else {
			cout << "No pertenece a conjunto" << endl;
		}

	}

}
void Utileria::print() {
	for (int i = 0; i < conjuntos.size(); i++) 
	{
		cout << conjuntos.at(i).at(0) << " = {";
		for (int j = 1; j < conjuntos[i].size(); j++) {
			if (j != conjuntos[i].size() - 1) {
				cout << conjuntos[i][j] << ",";
			}
			else {
				cout << conjuntos[i][j];
			}
			
			
		}
		cout << "}"<<endl;
	}

	

}
Utileria::~Utileria() {

}