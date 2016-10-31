#include <set>
#include <iostream>
#include <vector>
using namespace std;

//prueba 1


int datos[5][5] = { {0, 999, 4, 5, 999},
                    {3, 0, 5, 999, 999},
                    {999, 999, 0, 7, 1},
                    {999, 6, 999, 0, 9},
                    {6, 2, 999, 999, 0}};



/*

void dijkstra(int W[5][5]){ //matriz w con los valores de los arcos

    //int n = iSize;
    int L[n-1];//
    int T[n-1];//
    int min; //repetirn n-1 veces
    int vmin;
    int contadorRepeticiones = n - 1;


    for(int i = 2; i <= n; i++){ //recorre arreglo de 2 a n
        L[i] = W[1][i];
        T[i] = 1;
    }

    while(contadorRepeticiones > 0){

        min = 999999;

        for(int i = 2; i <= n; i++){ //recorre arreglo de 2 a n

            if(0 <= L[i] <= min){
                min = L[i];
                vmin = i;
            }
        }

        //agregar e a s

        for(int i = 2; i <= n; i++){ //recorre arreglo de 2 a n
            if(L[vmin] + W[vmin][i] < L[i]){
                L[i] = L[vmin] + W[vmin][i];
                T[i] = vmin;
            }
        }

        L[vmin] = -1; //control para que ya no se considere en la busqueda del menor

        contadorRepeticiones--;
    }
}
*/



void camino(int T[], int v, int nodo){

    if (T[v] != nodo)  {
        camino(T, T[v], nodo);
        cout << "-" << T[v];
    }
}


int iSize = 5;


void dijkstra2(int W[5][5], int nodo){ //W grafos representados en matrices

    int L[iSize + 1];
    int T[iSize + 1];
    int min;
    int vmin;
    int R[iSize + 1]; // resultados
    int contadorRepeticiones = iSize - 1;

    //arranque con arreglos auxiliares
    for (int i = 2; i<=iSize; i++){
        L[i] = W[0][i-1];   //[0][] porque es el primer renglon.
                            //[][i-1] porque se guarda desde la
                            //segunda posicion hasta la ultima
        T[i] = 1; // se iniciliza T porque todavia no pasa por nodos
    }

    //resto del algoritmo
    while(contadorRepeticiones > 0){
        min = 999999;

        //selecciona el menor de las opciones en arreglo L
        for (int i = 2; i<= iSize; i++){
            if ( 0 <= L[i] && L[i] <= min){
                min=L[i];
                vmin=i;
            }
        }

        //actualiza arreglo R y arreglo T
        for (int i=2; i<= iSize; i++){

            if (L[vmin] + W[vmin - 1][i - 1] < L[i]){
                L[i] = L[vmin] + W[vmin - 1][i - 1];
                T[i] = vmin;
            }

        }

        R[vmin] = L[vmin];
        L[vmin] = -1;

        contadorRepeticiones--;
    }


    cout << endl;
    cout << "Caminos" << endl;
    for (int i = 2; i <= iSize; i++){
        cout << nodo << " a " << i << ": " << nodo;
        camino(T, i, nodo);
        cout << "-" << i << " cuesta " << R[i] << " unidades" << endl;;
    }

}

void printMatrix(int arr[5][5], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << '\t';
        }

        cout << endl;
    }

}





int main() {

    dijkstra2(datos, 1);


    return 0;
}
