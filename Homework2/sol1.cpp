using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <chrono>

//Sergio Diaz
//A01192313
// cd sdn/TEC/V/Algoritmos/Tareas/Tarea_2/Algoritmos-Tarea2/
///////////////////////////////////////////////////////////////////////////////////////////////
//Solucion #1

//Globales
string sArchivo = "matriculas.txt";
clock_t timeSol1 = clock();

//Arreglo para solución #1
int iSize = 154750;
int arr1[154750];


void printComparaciones(int iNumero){

	cout << "Comparaciones: " << iNumero << endl;

}

//Le archivo de texto y mete en el arreglo a las matriculas
void leeArchivo1(){
	ifstream matriculas;
	matriculas.open(sArchivo);
	int iNumero;
	int iPosicion = 0;

	while (matriculas >> iNumero) {
		arr1[iPosicion] = iNumero;
		iPosicion++;
	}
	matriculas.close();
}

bool buscarArreglo(int iDato){

	int iComparaciones = 0;

	for (int i = 0; i < iSize; i++) {

		iComparaciones++;

		if  (arr1[i] == iDato) {
			printComparaciones(iComparaciones);
			return true;
		}

	}
	
	printComparaciones(iComparaciones);
	return false;
}



void tiempo(){
	timeSol1 = clock() - timeSol1;
	double ms = double(timeSol1) / CLOCKS_PER_SEC * 1000;
	cout << "time sol 1: " << ms << endl;
}


void solucion1(int iDato){


	leeArchivo1();

	if (buscarArreglo(iDato)) {
		cout << "Dato encontrado" << endl;
	}
	else {
		cout << "Dato NO encontrado" << endl;
	}
	tiempo();
}

int main(int argc, char const *argv[]) {

	int iDato;
	cout << "Matricula -> "  << " ";
	cin >> iDato;

	while (iDato != -1) {
		solucion1(iDato);
		timeSol1 = clock();
		cout << "si quiere salir ponga -1" << endl;
		cout << "Matricula -> "  << " ";
		cin >> iDato;
	}
}
