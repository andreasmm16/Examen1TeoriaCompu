#include "utileria.h"
#include <string>
#include <iostream>
#include <locale.h>

using namespace std;


int main() {

	int num = 0;
	setlocale(LC_ALL, "spanish");
	Utileria utils;

	do {

		cout <<endl<< "--Opciones--" << endl<<"1.Crear Conjunto\n2.Agregar a Conjunto\n3.Quitar de Conjunto\n4.Verificar si pertenece\n5.Comparar conjuntos\n6.Imprimir\n7.Salir\n\nIngrese el número con la opción deseada:";
		cin >> num;

		switch (num) {

		case 1:
			utils.crearConjunto();
			break;
		case 2:
			utils.agregar();
			break;

		case 3:
			utils.quitar();
			break;

		case 4:
			utils.checkPertenece();
			break;
		case 5:
			utils.comparar();
			break;
		case 6:
			utils.print();
			break;
		}
	} while (num != 7);

}
