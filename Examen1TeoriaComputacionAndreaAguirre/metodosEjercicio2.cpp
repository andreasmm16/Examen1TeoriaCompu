#include <iostream>
#include "metodosEjercicio2.h"
#include <string>
#include <fstream>
#include <windows.h> 

using namespace std;


metodosEjercicio2::metodosEjercicio2() {
	ing = "";
	//inicializar tabla de verdad de juego
	arr = new int* [5];
	for (int i = 0; i < 5; i++) {
		arr[i] = new int[5];
	}
}

void metodosEjercicio2::tablaJuego() {
	cout << "--TABLA DEL JUEGO \"PIEDRA PAPEL ¿SPOCK?--\""<<endl;
	cout << "Nombre de archivo con grafo de lógica de juego: GrafoJuego.txt\nGrafo en notación algebraica: ";
	ifstream filee;
	string grafotxt = "";
	filee.open("GrafoJuego.txt");
	if (filee) {
		while (!filee.eof()) {
			getline(filee, grafotxt);
		}
		cout << grafotxt << endl;
	}
	else {
		cout << "Archivo no puede ser ubicado" << endl;
		return;
	}
	filee.close();
	cout << endl;
	cargarGrafo();

	

}

void metodosEjercicio2::juego() {

}

void metodosEjercicio2::cargarGrafo() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int posGrafo = 0 , posc = 0, posf = 0;
	ifstream filee;
	string grafotxt = "", tmpp = "";
	filee.open("GrafoJuego.txt");
	if (filee) {
		while (!filee.eof()) {
			getline(filee, grafotxt);
		}
	}
	else {
		cout << "Archivo no puede ser ubicado" << endl;
		return;
	}
	filee.close();
	tmpp = grafotxt.at(0);
	grafo.push_back(tmpp);
	grafo.push_back("{");
	tmpp = "";
	//meter vértices en vector
	for (int x = 3; x < grafotxt.size(); x++) {
		if (grafotxt.at(x) != '}') {
			if (grafotxt.at(x) != ',') {
				tmpp += grafotxt.at(x);
			}
			else {
				if (x != 0) {
					grafo.push_back(tmpp);
					tmpp = "";
				}
			}
		}
		else {
			grafo.push_back(tmpp);
			tmpp = "";
			break;
		}
	}
	grafo.push_back("}");
	grafo.push_back("{");
	//meter edges/aristas
	for (int x = 17; x < grafotxt.size(); x++) {
		if (grafotxt.at(x) != '}') {
			if (grafotxt.at(x) != '(' & grafotxt.at(x) != ',' && grafotxt.at(x) != ')') {
				tmpp += grafotxt.at(x);
			}
			else {
				if (x != 0 && tmpp != "") {
					grafo.push_back(tmpp);
					tmpp = "";
				}
			}
		}
		else {
			grafo.push_back(tmpp);
			tmpp = "";
			break;
		}
		
	}
	//lenar tabla con 0s
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			arr[x][y] = 0;
		}
	}
	//llenar tabla con 1s
	for (int x = 9; x < grafo.size() - 1; x++) {
		tmpp = grafo.at(x);
		for (int y = 2; y < 5 + 2; y++) {
			if (grafo.at(y) == tmpp) {
				posc = y - 2;
			}
		}
		x++;
		tmpp = grafo.at(x);
		for (int a = 2; a < 5 + 2; a++) {
			if (grafo.at(a) == tmpp) {
				posf = a - 2;
			}
		}
		arr[posf][posc] = 1;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "    ";
	for (int x = 2; x < 7; x++) {
		if (grafo.at(x) == "PI") {
			SetConsoleTextAttribute(h, 4);
			cout << grafo.at(x) << "   ";
		}
		else if (grafo.at(x) == "PA") {
			SetConsoleTextAttribute(h, 6);
			cout << grafo.at(x) << "   ";
		}
		else if (grafo.at(x) == "T") {
			SetConsoleTextAttribute(h, 5);
			cout << grafo.at(x) << "    ";
		}
		else if (grafo.at(x) == "L") {
			SetConsoleTextAttribute(h, 2);
			cout << grafo.at(x) << "    ";
		}
		else if (grafo.at(x) == "S") {
			SetConsoleTextAttribute(h, 9);
			cout << grafo.at(x) << "   ";
		}
		
	}
	SetConsoleTextAttribute(h, 7);
	cout << endl;
	for (int x = 0; x < 5; x++) {
		if (grafo.at(x + 2) == "PI") {
			SetConsoleTextAttribute(h, 4);
			cout << grafo.at(x+2) << "  ";
		}
		else if (grafo.at(x + 2) == "PA") {
			SetConsoleTextAttribute(h, 6);
			cout << grafo.at(x+2) << "  ";
		}
		else if (grafo.at(x + 2) == "T") {
			SetConsoleTextAttribute(h, 5);
			cout << grafo.at(x+2) << "   ";
		}
		else if (grafo.at(x + 2) == "L") {
			SetConsoleTextAttribute(h, 2);
			cout << grafo.at(x+2) << "   ";
		}
		else if (grafo.at(x + 2) == "S") {
			SetConsoleTextAttribute(h, 9);
			cout << grafo.at(x+2) << "   ";
		}
		SetConsoleTextAttribute(h, 7);
		for (int y = 0; y < 5; y++) {
			cout << arr[x][y] << "    ";

		}
		SetConsoleTextAttribute(h, 7);
		cout << endl;
	}

}
metodosEjercicio2::~metodosEjercicio2() {

}