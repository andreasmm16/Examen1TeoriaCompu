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
	cout <<endl<< "--TABLA DEL JUEGO \"PIEDRA PAPEL ¿SPOCK?--\""<<endl;
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string p1 = "", p2 = "",sino="";
	int fila = 0, col = 0;
	cout << "--JUGAR \"PIEDRA PAPEL ¿SPOCK?--\"\n¡Para salir en cualquier momento del juego escribe \"SALIR\"!\n";
	cout << "Tabla de estructura del juego:" << endl;
	cargarGrafo();
	cout << endl;
c:	cout << "\nTeclas para jugar : \nPiedra--> 1\nPapel--> 2 \nTijera--> 3\nLagartija--> 4\nSpock--> 5\n\n * --INICIO DE PARTIDA-- * \n";
	
a:	
	SetConsoleTextAttribute(h, 1);
	cout << "Jugador 1: ";
	SetConsoleTextAttribute(h, 7);
	int result = 0;
	cin >> p1;
	if (p1 == "SALIR") {
		return;
	}
	if (p1 != "1" && p1 != "2" && p1 != "3" && p1 != "4" && p1 != "5" && p1 != "6") {
		cout << "Opción no válida" << endl;
		goto a;
	}
b:
	SetConsoleTextAttribute(h, 3);
	cout << "Jugador 2: ";
	SetConsoleTextAttribute(h, 7);
	cin >> p2;
	if (p2 == "SALIR") {
		return;
	}
	if (p2 != "1" && p2 != "2" && p2 != "3" && p2 != "4" && p2 != "5" && p2 != "6") {
		cout << "Opción no válida" << endl;
		goto b;
	}
	if (p1 == p2) {
		SetConsoleTextAttribute(h, 6);
		cout << "¡Es un empate! \n";
		SetConsoleTextAttribute(h, 7);
	f:	cout << "¿ Jugar partida nueva ? Ingresa Si o No:";
		cin >> sino;
		if (sino == "Si" || sino == "si" || sino == "SI") {
			goto c;
		}
		else if (sino == "No" || sino == "no" || sino == "NO") {
			return;
		}
		else if (sino != "No" || sino != "no" || sino != "NO" || sino != "Si" || sino != "si" || sino != "SI" || sino != "SALIR") {
			cout << "\nIngresar solo 1 ó 2 ó SALIR" << endl;
			goto f;
		}
	}
	result = arr[stoi(p2) - 1][stoi(p1) - 1];
	if (result == 1) {
		SetConsoleTextAttribute(h, 1);
		cout << "¡Jugador 1 es el ganador! \n";
		SetConsoleTextAttribute(h, 7);
	d:	cout << "¿ Jugar partida nueva? Ingresa Si o No:";
		cin >> sino;
		if (sino == "Si" || sino == "si" || sino == "SI") {
			goto c;
		}
		else if (sino == "No" || sino == "no" || sino == "NO") {
			return;
		}
		else if (sino != "No" || sino != "no" || sino != "NO" || sino != "Si" || sino != "si" || sino != "SI" || sino != "SALIR") {
			cout << "\nIngresar solo 1 ó 2 ó SALIR" << endl;
			goto d;
		}
	}
	else if (result == 0) {
		SetConsoleTextAttribute(h,3);
		cout << "¡Jugador 2 es el ganador! \n";
		SetConsoleTextAttribute(h, 7);
	e:	cout << "¿ Jugar partida nueva ? Ingresa Si o No:";
		cin >> sino;
		if (sino == "Si" || sino == "si" || sino == "SI") {
			goto c;
		}
		else if (sino == "No" || sino == "no" || sino == "NO") {
			return;
		}
		else if (sino != "No" || sino != "no" || sino != "NO" || sino != "Si" || sino != "si" || sino != "SI" || sino != "SALIR") {
			cout << "\nIngresar solo 1 ó 2 ó SALIR" << endl;
			goto e;
		}
	}

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
			if (grafotxt.at(x) != '(' && grafotxt.at(x) != ',' && grafotxt.at(x) != ')') {
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