//Sergio Díaz
//A01192313

using namespace std;
#import <iostream> 
#include <fstream>


int const iSize = 10000;
int iComparaciones = 0;
string sArchivo = "random.txt";


void leeArchivo(int arr[iSize]){
	ifstream randomNumbers;
	randomNumbers.open(sArchivo);
	int iPosicion = 0;
	int iNumero;

	while (randomNumbers >> iNumero) {
		arr[iPosicion] = iNumero;
		iPosicion++;
	}

	randomNumbers.close();
}
void llenaArreglos(int menorMayor[iSize], int mayorMenor[iSize], int arrRandom[iSize]) {
    
    //Menor a mayor
    for(int i = 1; i < iSize; i++){
        menorMayor[i] = i;
    }

    //Mayor a menor
    for(int i = iSize - 1; i > 0 ; i--){
        mayorMenor[i] = i;
    }

    //random
    leeArchivo(arrRandom);
}


void merge(int arr[], int iFirst, int iMiddle, int iLast){

	int iI = iFirst;
	int iJ = iMiddle + 1;
	int iK = iFirst;
	int aux[iSize];

	while (iI <= iMiddle && iJ <= iLast) {

		if (arr[iI] >= arr[iJ]) {
			aux[iK] = arr[iI];
			iI = iI + 1;
			iComparaciones++;

		} else {
			aux[iK] = arr[iJ];
			iJ = iJ + 1;
			iComparaciones++;
		}

		iK = iK + 1;
	}



	if (iI > iMiddle) {

		iComparaciones++;
		while (iJ <= iLast) {

			aux[iK] = arr[iJ];
			iK = iK + 1;
			iJ = iJ + 1;
		}

	} else {

		iComparaciones++;
		while (iI <= iMiddle) {
			aux[iK] = arr[iI];
			iK = iK + 1;
			iI = iI + 1;
		}
	}
	

	for (int i = iFirst; i < iK; i++){

		arr[i] = aux[i];
		//cout << arr[i] <<  endl;
	}

	//cout << endl;
}



void mergeSort(int arr[], int iFirst, int iLast){


	if (iFirst < iLast) {

		int iMiddle = ((iFirst + iLast) / 2);
		mergeSort(arr, iFirst, iMiddle);
		mergeSort(arr, iMiddle + 1, iLast);
		merge(arr,iFirst, iMiddle , iLast);		
	}
}


int main(){


	int menorMayor[iSize];
	int mayorMenor[iSize];
	int random[iSize];

	llenaArreglos(menorMayor, mayorMenor, random);

	mergeSort(menorMayor, 0, iSize - 1);
	cout << "        Prueba A: datos ordenados merge sort's comparisons: "  << iComparaciones << endl;


	iComparaciones = 0;
	mergeSort(mayorMenor, 0, iSize - 1);
	cout << "Prueba B: datos con orden inverso merge sort's comparisons: "  << iComparaciones << endl;


	iComparaciones = 0;
	mergeSort(random, 0, iSize - 1);
	cout << "       Prueba C: datos aleatorios merge sort's comparisons: "  << iComparaciones << endl;

}