//Sergio Díaz
//A01192313
using namespace std;
#import <iostream> 
#include <fstream>


int const iSize = 10000;
int iIntercambios = 0;
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


int Particion(int arr[], int iInicio, int iFin) {
    
    int iElementoPivote = arr[iInicio], iJ = iInicio, aux;
    
    for (int i = iInicio + 1; i <= iFin; i++) {
        if (arr[i] >= iElementoPivote){
            iJ++;
            aux = arr[i];
            arr[i] = arr[iJ];
            arr[iJ] = aux;
            iIntercambios++;
        }
    }
    
    aux = arr[iInicio];
    arr[iInicio] = arr[iJ];
    arr[iJ] = aux;
    iIntercambios++;
    return iJ;
}

void QuickSort(int arr[], int iInicio, int iFin) {
    
    if (iInicio < iFin) {
        int iPivote = Particion(arr, iInicio, iFin);
        QuickSort(arr, iInicio, iPivote - 1);
        QuickSort(arr, iPivote + 1, iFin);
    }
}


int main(){

	int menorMayor[iSize];
	int mayorMenor[iSize];
	int random[iSize];

	llenaArreglos(menorMayor, mayorMenor, random);

	QuickSort(menorMayor, 0, iSize - 1);
	cout << "        Prueba A: datos ordenados quick sort's swaps: "  << iIntercambios << endl;

	iIntercambios = 0;
	QuickSort(mayorMenor, 0, iSize - 1);
	cout << "Prueba B: datos con orden inverso quick sort's swaps: "  << iIntercambios << endl;

	iIntercambios = 0;
	QuickSort(random, 0, iSize - 1);
	cout << "       Prueba C: datos aleatorios quick sort's swaps: "  << iIntercambios << endl;


}