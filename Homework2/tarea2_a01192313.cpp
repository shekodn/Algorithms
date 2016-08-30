using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>     // std::string, std::stoi
#include <sys/time.h>
#include <chrono>



//Sergio Diaz
//A01192313


//Globales
string sArchivo = "matriculas.txt";
clock_t timeSol1 = clock();
//clock_t timeSol2 = clock();
//clock_t timeSol3 = clock();


// cd sdn/TEC/V/Algoritmos/Tareas/Tarea_2/Algoritmos-Tarea2/
////////////////////////////////////////////////////////////////////////////////////////////////
//Solucion #1
//Arreglo para solución #1
int iSize = 154750;
int arr1[154750];

//mock
//int arr1[10];
//int iSize = 10;

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

void buscarArreglo(int iDato){

	bool find = false;

	for (int i = 0; i < iSize; i++) {
		if  (arr1[i] == iDato) {
			find = true;
			break;
		}
	}

	if (find) {
		cout << "Dato encontrado" << endl;
	}

	else {
		cout << "Dato NO encontrado" << endl;
	}
}



void solucion1(int iDato){

	//cout << "Solucion #1" << endl;
	leeArchivo1();
	buscarArreglo(iDato);


}


////////////////////////////////////////////////////////////////////////////////////////////////
//Solucion #2

vector<int> v;  //vector donde se colocan las maticulas

//Le archivo de texto y mete en el vector a las matriculas
void leeArchivo2(){

	ifstream matriculas;
	matriculas.open(sArchivo);
	int iNumero;

	while (matriculas >> iNumero) {
		v.push_back(iNumero);
	}

	//Se ordena el vector en forma ascendiente
	sort(v.begin(), v.end());

	//se impirme vector
	/*
	cout << "Vector:" << endl;
  	for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
    cout << * it << endl;
  	cout << endl;
  	*/

  	matriculas.close();

}

void bSearch2(int iDato){

	//binary search
  	if (binary_search(v.begin(), v.end(), iDato)) {

  		cout << "Dato encontrado" << endl;
    }

    else {

    	cout << "Dato NO encontrado" << endl;
    }
}


void solucion2(int iDato){

	leeArchivo2();
	bSearch2(iDato);

}

////////////////////////////////////////////////////////////////////////////////////////////////
//Solucion #3

int arrHash[1000]; //arreglo estático de 1000 posiciones

void nullInit(int arr[1000]){

	for(int i = 0; i < 1000; i++){

	}
}

void solucion3(int iDato){




}

//Le archivo de texto y mete en el arreglo a las matriculas
void leeArchivo3(){

	ifstream matriculas;
	matriculas.open(sArchivo);
	int iNumero;

	while (matriculas >> iNumero) {
	}

	matriculas.close();
}



int funcionHash(int iNumero){

	iNumero = iNumero % 1000;

	return iNumero;
}




int main(int argc, char const *argv[]) {



	int iDato = 744997;

	//cout << "Inserte la matricula que quiere buscar, si quiere salir ponga -1" << endl;
	//cin >> iDato;


	//while (iDato != -1) {

		//Solucion 1
		//solucion1(iDato);

		//Solucion 2
		//solucion2(iDato);

		//Solucion 3
		//solucion3(iDato);

		//cout << "Si quiere insertar un dato ponga 1, si quiere salir ponga 0" << endl;
		//cin >> iDato;

	//}


	cout << "Posicion" << funcionHash(5289313) << " " << endl;;


	timeSol1 = clock() - timeSol1;

	double ms = double(timeSol1) / CLOCKS_PER_SEC * 1000;

	cout << "time: " << ms << endl;

}
