using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>     // std::string, std::stoi
#include <sys/time.h>
#include <chrono>
#include <list>
#include <array>

////////////////////////////////////////////////////////////////////////////////
//Solucion #3
string sArchivo = "matriculas.txt";
clock_t timeSol3 = clock();

void printComparaciones(int iNumero){

	cout << "Comparaciones: " << iNumero << endl;

}

//regresa los ultimos 3 digitos de la matricula
int funcionHash(int iMatricula){
	return iMatricula % 1000;
}

//Le archivo de texto y mete matriculas al hash
void leeArchivo3(array<list<int>, 1000> &iMatriculas){

	ifstream matriculas;
	matriculas.open(sArchivo);
	int iMatricula;
	int iLlave;

	while (matriculas >> iMatricula){
		iLlave = funcionHash(iMatricula);
		iMatriculas[iLlave].push_back(iMatricula);
	}
	matriculas.close();
}

//una funcion para contar el tiempo de ejecucion
void tiempo(clock_t tiempo){
	tiempo = clock() - tiempo;
	double ms = double(tiempo) / CLOCKS_PER_SEC * 1000;
	cout << "time: " << ms << endl;
}

bool buscarMatricula(int iDato, array< list <int>, 1000> iMatriculas) {

	int iLlave = funcionHash(iDato);
	int iComparaciones = 0;

	while (!iMatriculas[iLlave].empty()){

		iComparaciones++;

		if (iMatriculas[iLlave].front() == iDato) {
			printComparaciones(iComparaciones);
			return true;
		}
		else {
			iMatriculas[iLlave].pop_front();
		}
	}
	printComparaciones(iComparaciones);
	return false;
}


void solucion3(int iDato){
  array<list<int>, 1000> iMatriculas;
  array<list<int>, 1000> iMatriculas2;
  leeArchivo3(iMatriculas);

  if (buscarMatricula(iDato, iMatriculas)) {
  	cout << "Dato encontrado" << endl;
  }
  else {
  	cout << "Dato NO encontrado" << endl;
  }
  tiempo(timeSol3);
}

int main(int argc, char const *argv[]) {

	int iDato;
	cout << "Matricula -> "  << " ";
	cin >> iDato;

	while (iDato != -1) {
		solucion3(iDato);
		timeSol3 = clock();
		cout << "si quiere salir ponga -1" << endl;
		cout << "Matricula -> "  << " ";
		cin >> iDato;
	}

}
