#include <iostream>
#include "metodosEjercicio1.h"
#include <string>
#include <fstream>
using namespace std;

metodosEjercicio1::metodosEjercicio1() {
	c = "";
	tmp = 0;
}


void metodosEjercicio1::crearGrafo() {
	c = "";
	tmp = 0;
	string siono = "";
	vector<string> v1;
	ifstream filee;
	cout << "***CREAR GRAFO***\n-->Para salir en cualquier momento ingresar \"SALIR\"\n\nIngrese nombre de grafo:";
	cin >> c;

	if (c == "SALIR") {
		return;
	}

	for (int x = 0; x < grafos.size(); x++)
	{
		if (grafos.at(x).at(0) == c) {
			tmp = 1;
		}
	}

	if (tmp == 0) {
		v1.push_back(c);
		//PEDIR ELEMENTOS DE V
	a:	cout << endl << "Ingrese elementos de V en forma {V}\n-->Ejemplo: {1,2,3}--\nPrimero indicar si serán ingresados mediante consola o archivo de texto plano:\n1.Archivo de texto (.txt)\n2.Consola\nIngrese número de opción:";
		cin >> siono;

		if (siono == "SALIR") {
			return;
		}
		else if (siono == "1") {
		d:	cout << endl << "Ingrese nombre de archivo en este formato \"nombre.txt\" -->";
			cin >> c;
			if (c == "SALIR") {
				return;
			}
			filee.open(c);
			if (filee) {
				while (!filee.eof()) {
					getline(filee, c);
				}
			}
			else {
				cout << "Archivo no existe" << endl;
				goto d;
			}
			filee.close();
		}
		else if (siono == "2") {
			cout << endl << "Ingrese los elementos de V en forma {V}" << endl << ":";
			cin >> c;
		}
		else if (siono != "1" || siono != "2") {
			cout << "\nIngresar solo 1 ó 2 ó SALIR" << endl;
			goto a;
		}

		for (int x = 0; x < c.size(); x++) {
			if (isspace(c[x])) {
				cout << "No pueden ir espacios vacíos" << endl;
				goto a;
			}
		}

		if (validacionV(c)) {
		b:	cout << endl << "Elementos para V ingresados: " << c << endl << "¿Confirma elementos ingresados? Ingresar Si o No:";
			cin >> siono;
			if (siono == "SALIR") {
				return;
			}
			else if (siono == "Si" || siono == "si" || siono == "SI") {
				goto c;
			}
			else if (siono == "No" || siono == "no" || siono == "NO") {
				goto a;
			}
			else if (siono != "No" || siono != "no" || siono != "NO" || siono != "Si" || siono != "si" || siono != "SI" || siono != "SALIR") {
				cout << "\nIngresar solo 1 ó 2 ó SALIR" << endl;
				goto b;
			}

		c:
			v1.push_back("{");
			string tm = "";
			for (int x = 0; x < c.size(); x++) {
				if (c.at(x) != '{' && c.at(x) != '}' && c.at(x) != ',') {
					tm += c.at(x);
				}
				else {
					if (x != 0) {
						v1.push_back(tm);
						tm = "";
					}
				}
			}
			v1.push_back("}");
			int con = 0;
			//Eliminar duplicados
			for (int x = 0; x < v1.size(); x++) {
				tm = v1.at(x);
				for (int a = 0; a < v1.size(); a++) {
					if (v1.at(a) == tm && tm != ",") {
						con++;
					}
				}
				if (con > 1) {
					for (int q = 0; q < v1.size(); q++) {
						if (v1.at(q) == tm) {
							v1.erase(v1.begin() + q);
							con--;
						}
						if (con == 1) {
							break;
						}
					}
				}
				con = 0;
			}

			//PEDIR ELEMENTOS DE E
		f:	cout << endl << "Ingrese elementos de E en forma {E} recordando que son pares ordenados\n-->Ejemplo: {(1,2),(1,3),(3,2)}--\nPrimero indicar si serán ingresados mediante consola o archivo de texto plano:\n1.Archivo de texto (.txt)\n2.Consola\nIngrese número de opción:";
			cin >> siono;
			if (siono == "SALIR") {
				return;
			}
			else if (siono == "1") {
			e:	cout << endl << "Ingrese nombre de archivo en este formato \"nombre.txt\" -->";
				cin >> c;
				if (c == "SALIR") {
					return;
				}
				filee.open(c);
				if (filee) {
					while (!filee.eof()) {
						getline(filee, c);
					}
				}
				else {
					cout << "Archivo no existe" << endl;
					goto e;
				}
				filee.close();
			}
			else if (siono == "2") {
				cout << endl << "Ingrese los elementos de E en forma {E} recordando que son pares ordenados\n-->Ejemplo: {(1,2),(1,3),(3,2)}" << endl << ":";
				cin >> c;
			}
			else if (siono != "1" || siono != "2") {
				cout << "\nIngresar solo 1 ó 2 ó SALIR";
				goto f;
			}
			for (int x = 0; x < c.size(); x++) {
				if (isspace(c[x])) {
					cout << "No pueden ir espacios vacíos" << endl;
					goto f;
				}
			}
			if (validacionE(c)) {
				//Verificar si elementos existen en vértices
				tmp = 0;
				siono = "";
				for (int x = 2; x < c.size() - 1; x++) {
					if (c.at(x) != ',' && c.at(x) != '(' && c.at(x) != ')') {
						siono += c.at(x);
					}
					else {
						if (siono != "") {
							for (int a = 0; a < v1.size(); a++) {
								if (siono == v1.at(a)) {
									tmp = 1;
								}
							}
							if (tmp == 0) {
								cout << "Nombre de vértice no existe en grafo" << endl;
								goto f;
							}
							siono = "";
							tmp = 0;
						}
					}
				}
				//aqui ya validó que existen elementos de E en V
			g:	cout << endl << "Elementos para E ingresados: " << c << endl << "¿Confirma elementos ingresados? Ingresar Si o No:";
				cin >> siono;
				if (siono == "SALIR") {
					return;
				}
				else if (siono == "Si" || siono == "si" || siono == "SI") {
					goto h;
				}
				else if (siono == "No" || siono == "no" || siono == "NO") {
					goto f;
				}
				else if (siono != "No" || siono != "no" || siono != "NO" || siono != "Si" || siono != "si" || siono != "SI" || siono != "SALIR") {
					cout << "Ingrese solo Si o No o SALIR";
					goto g;
				}
			h:
				v1.push_back("{");
				tm = "";
				for (int x = 0; x < c.size(); x++) {
					if (c.at(x) != '{' && c.at(x) != '}' && c.at(x) != ',' && c.at(x) != '(' && c.at(x) != ')') {
						tm += c.at(x);
					}
					else {
						if (x != 0 && tm != "") {
							v1.push_back(tm);
							tm = "";
						}
					}
				}
				v1.push_back("}");
				grafos.push_back(v1);
				cout << "¡Grafo ingresado correctamente!" << endl;

			}
			else {
				goto f;
			}

		}
		else {
			goto a;
		}

	}
	else {
		cout << "Grafo ya existe" << endl;
	}

}

void metodosEjercicio1::printMatrizGrafo() {
	int posGrafo = 0, cantV = 0, posEs = 0, posc = 0, posf = 0;
	string tm = "";
a:
	cout << endl << "***REPRESENTAR GRAFO EN MATRIZ***\n-->Para salir en cualquier momento ingresar \"SALIR\"\n\nIngrese nombre de grafo:";
	cin >> c;

	if (c == "SALIR") {
		return;
	}
	for (int x = 0; x < grafos.size(); x++)
	{
		if (grafos.at(x).at(0) == c) {
			posGrafo = x;
			tmp = 1;
		}
	}

	if (tmp == 1) {
		//determinar la cantidad de vértices
		for (int x = 2; x < grafos.at(posGrafo).size(); x++) {
			if (grafos.at(posGrafo).at(x) != "}") {
				cantV++;
			}
			else {
				posEs = cantV + 4;
				break;
			}
		}
		//hacer formato de columas y filas de matriz
		int** arr = new int* [cantV];
		for (int i = 0; i < cantV; i++) {
			arr[i] = new int[cantV];
		}

		//lenar matrices con 0s
		for (int x = 0; x < cantV; x++) {
			for (int y = 0; y < cantV; y++) {
				arr[x][y] = 0;
			}
		}

		//llenar matriz con 1s
		for (int x = posEs; x < grafos.at(posGrafo).size() - 1; x++) {
			tm = grafos.at(posGrafo).at(x);
			for (int y = 2; y < cantV + 2; y++) {
				if (grafos.at(posGrafo).at(y) == tm) {
					posc = y - 2;
				}
			}
			x++;
			tm = grafos.at(posGrafo).at(x);
			for (int a = 2; a < cantV + 2; a++) {
				if (grafos.at(posGrafo).at(a) == tm) {
					posf = a - 2;
				}
			}
			arr[posf][posc] = 1;
			arr[posc][posf] = 1;
		}
		cout << "   ";
		for (int x = 2; x < cantV + 2; x++) {
			cout << grafos.at(posGrafo).at(x) << "  ";
		}
		cout << endl;
		for (int x = 0; x < cantV; x++) {
			cout << grafos.at(posGrafo).at(x + 2) << "  ";
			for (int y = 0; y < cantV; y++) {
				cout << arr[x][y] << "  ";

			}
			cout << endl;
		}
	}
	else {
		cout << "Grafo no existe" << endl;
		goto a;
	}


}

void metodosEjercicio1::etiquetarVertice() {
	int posGrafo = 0, cantV = 0;
	string tm = "";
	tmp = 0;
a:
	cout << endl << "***ETIQUETAR UN VÉRTICE***\n-->Para salir en cualquier momento ingresar \"SALIR\"\n\nIngrese nombre de grafo:";
	cin >> c;

	if (c == "SALIR") {
		return;
	}
	for (int x = 0; x < grafos.size(); x++)
	{
		if (grafos.at(x).at(0) == c) {
			posGrafo = x;
			tmp = 1;
		}
	}

	if (tmp == 1) {
	b:		cout << "Ingrese nombre de etiqueta a modificar: ";
		cin >> c;
		if (c == "SALIR") {
			return;
		}
		//validar si vértice existe
		for (int x = 2; x < grafos.at(posGrafo).size(); x++) {
			if (grafos.at(posGrafo).at(x) != "}") {
				cantV++;
			}
			else {
				break;
			}
		}
		tmp = 0;
		for (int x = 2; x < cantV + 2; x++) {
			if (c == grafos.at(posGrafo).at(x)) {
				tmp = 1;
			}
		}
		if (tmp == 1) {
			cout << "Inserte nueva etiqueta: ";
			cin >> tm;
			if (tm == "SALIR") {
				return;
			}
			for (int x = 2; x < cantV + 2; x++) {
				if (c == grafos.at(posGrafo).at(x)) {
					grafos.at(posGrafo).at(x) = tm;
				}
			}
			cout << "¡Etiqueta modificada!" << endl;
		}
		else {
			cout << "¡Vértice no existe en este grafo!" << endl;
			goto b;
		}

	}
	else {
		cout << "Grafo no existe" << endl;
		goto a;
	}
}


bool metodosEjercicio1::validacionV(string V) {
	int siz = V.size();
	if (V[siz - 1] != '}') {
		cout << "Último carácter debe ser \"}\"" << endl;
		return false;
	}
	else if (V[0] != '{') {
		cout << "Primer carácter debe ser \"{\"" << endl;
		return false;
	}
	else if (V[siz - 1] == '}' && V[0] == '{' && siz == 2) {
		cout << "Elementos vacíos" << endl;
		return false;
	}
	else if (siz > 2 && V[siz - 2] == ',') {
		cout << "Elementos no pueden terminar en coma \",\"" << endl;
		return false;
	}

	return true;
}

bool metodosEjercicio1::validacionE(string E) {
	int siz = E.length();
	if (E[siz - 1] != '}') {
		cout << "Último carácter debe ser \"}\"" << endl;
		return false;
	}
	else if (E[0] != '{') {
		cout << "Primer carácter debe ser \"{\"" << endl;
		return false;
	}
	else if (E[siz - 1] == '}' && E[0] == '{' && siz == 2) {
		cout << "Elementos vacíos" << endl;
		return false;
	}
	else if (E[1] != '(') {
		cout << "Elementos deben ser ingresados como par ordenados --> (num,num) comenzando con paréntesis" << endl;
		return false;
	}
	else if (E[siz - 2] == ',') {
		cout << "{E} no puede terminar en coma --> {(),}" << endl;
		return false;
	}
	int leftPar = 0, rightPar = 0, cont = 0;
	for (int x = 0; x < E.size(); x++)
	{
		if (E.at(x) == '(') {
			leftPar++;
		}
		else if (E.at(x) == ')') {
			rightPar++;
		}

		if (leftPar == rightPar) {
			leftPar = rightPar = 0;
		}
	}
	if (leftPar != rightPar) {
		cout << "¡Paréntesis Incompletos!" << endl;
		return false;
	}
	//Para verificar si es par ordenado
	for (int x = 1; x < E.size() - 1; x++) {
		if (E.at(x) == '(') {
			leftPar = 1;
		}
		else if (E.at(x) == ')') {
			rightPar = 1;
		}
		else if (E.at(x) == ',' && leftPar == 1) {
			cont++;
		}

		if (leftPar == rightPar) {
			if (cont > 1) {
				cout << "¡No pueden ir más de dos elementos dentro de la secuencia! Debe ser-->(num,num)" << endl;
				return false;
			}
			else {
				cont = 0, leftPar = 0, rightPar = 0;
			}
		}
	}
}

metodosEjercicio1::~metodosEjercicio1() {

}