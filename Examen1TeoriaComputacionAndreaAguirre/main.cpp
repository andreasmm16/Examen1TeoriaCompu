#include <iostream>
#include <string>
#include <Windows.h>
#include "metodosEjercicio1.h"
#include "metodosEjercicio2.h"

using namespace std;

int main()
{
	string num = "", num2="";
	setlocale(LC_ALL, "spanish");
	metodosEjercicio1 mets1;
	metodosEjercicio2 mets2;


	do {
	a:	cout << endl << "**--EXAMEN 1 TEORÍA DE COMPUTACIÓN--**" << endl << "1.Ejercicio 1\n2.Ejercicio 2\n3.Salir\n\nIngresar número de ejercicio:";
		cin >> num2;
		if (num2 != "1" && num2 != "2" && num2 != "3") {
			cout << "Opción ingresada no válida" << endl;
			goto a;
		}
		switch (stoi(num2)) {
		case 1:
			do {
		b:		cout << endl << "--EJERCICIO 1--" << endl << "1.Ingresar Grafo en forma \"G = ( {V},{E} )\".\n2.Imprimir Matriz de Grafo\n3.Etiquetar vértice\n4.Salir\n\nIngrese el número con la opción deseada:";
				cin >> num;
				if (num != "1" && num != "2" && num != "3" && num != "4") {
					cout << "Opción ingresada no válida" << endl;
					goto b;
				}
				switch (stoi(num)) {
				case 1:
					mets1.crearGrafo();
					break;

				case 2:
					mets1.printMatrizGrafo();
					break;

				case 3:
					mets1.etiquetarVertice();
					break;

				}
			} while (num != "4");

			break;

		case 2:
			do {
		c:		cout << endl << "--EJERCICIO 2--" << endl << "1.Mostrar tabla de verdad de Juego.\n2.Jugar \"Piedra Papel ¿Spock?\"\n3.Salir\n\nIngrese el número con la opción deseada:";
				cin >> num;
				if (num != "1" && num != "2" && num != "3") {
					cout << "Opción ingresada no válida" << endl;
					goto c;
				}
				switch (stoi(num)) {
				case 1:
					mets2.tablaJuego();
					break;
					
				case 2:

					break;

				}
			} while (num != "3");

			break;

		
		}

	} while (num2 != "3");
 
	
}