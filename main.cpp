#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void mostrarPresentacion() {
	cout << "======= SISTEMA DE CAPACITACIONES CAXTECH ======" << endl;
	cout << "Indicaciones de uso: " << endl;
	cout << "1) Ingresar la cantidad de empleados a evaluar." << endl;
	cout << "2) Ingresar la cantidad de modulos a evaluar." << endl;
	cout << "3) Ingresar los datos requeridos de cada empleado. " << endl;
	cout << "4) Revisar los resultados obtenidos." << endl;
}

int validarEmpleados() {
	int empleados;
	do {
		cout << "\nIngrese la cantidad de empleados: ";
		cin >> empleados;
		if (empleados < 1) {
			cout << "Error: Valor fuera de rango" << endl;
		}
	} while (empleados < 1);
	return empleados;
}

int validarModulos() {
	int modulos;
	do {
		cout << "\nIngrese la cantidad de modulos a evaluar: ";
		cin >> modulos;
		if (modulos < 1) {
			cout << "Error: Valor fuera de rango" << endl;
		}
	} while (modulos < 1);
	return modulos;
}

int main() {
	mostrarPresentacion();
	system("pause");
	system("cls");

	int n, k;
	char rpta;
	string nombre;
	double nota;
	double mejorprom = -1.0;
	string mejornombre = "";

	do {
		n = validarEmpleados();
		k = validarModulos();

		do {
			cout << "\nEsta seguro de los datos ingresados? (S)i / (N)o ===> ";
			cin >> rpta;
			if (rpta != 'S' && rpta != 's' && rpta != 'N' && rpta != 'n') {
				cout << "INGRESE UNA RESPUESTA PERMITIDA" << endl;
			}
		} while (rpta != 'S' && rpta != 's' && rpta != 'N' && rpta != 'n');

		if (rpta == 'N' || rpta == 'n') {
			cout << "\n--- Reiniciando configuracion ---" << endl;
		}

	} while (rpta == 'N' || rpta == 'n');

	cin.ignore();

	for (int i = 1; i <= n; i++) {
		double suma = 0.0;
		cout << "\n------------------------------------" << endl;
		cout << "TRABAJADOR " << i << ":" << endl;

		do {
			cout << "Ingrese nombre completo: ";
			getline(cin, nombre);
			if (nombre == "") {
				cout << "Error: Dato vacio" << endl;
			}
		} while (nombre == "");

		for (int j = 1; j <= k; j++) {
			do {
				cout << "Nota del modulo " << j << " (0-20): ";
				cin >> nota;
				if (nota < 0 || nota > 20) {
					cout << "Error: intente de nuevo" << endl;
				}
			} while (nota < 0 || nota > 20);
			suma = suma + nota;
		}

		cin.ignore();

		double prom = suma / k;
		cout << "\nPromedio obtenido de " << nombre << ": " << prom << endl;

		if (prom > mejorprom) {
			mejorprom = prom;
			mejornombre = nombre;
		}
	}

	cout << "\n===================================" << endl;
	cout << "Resultado final: " << endl;
	cout << "El mejor trabajador es " << mejornombre << " con promedio de " << mejorprom << endl;

	return 0;
}
