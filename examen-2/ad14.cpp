#include <cstdlib>
#include <iostream>
#include <queue>
//#include <array>

using namespace std;

void myHeapSort(int arr[]){

    int arrSize = sizeof(arr) - 1;

    //cout << "Arr size " << arrSize << endl;
    priority_queue<int> mypq;

    for(int i = 0; i < arrSize; i ++){
        mypq.push(arr[i]);
    }

    for(int i = arrSize - 1; i >= 0; i--){
        arr[i] = mypq.top();
        mypq.pop();
    }

    // for(int i = 0; i < arrSize; i++){
    //     cout << arr[i] << " ";
    // }
}

void printArr(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//////problema 2

//define tam 5

int tam = 5;
int iContadorColores = 0;

int datos[5][5] = {{0, 999, 4, 5, 999},
         		 {3, 0, 5, 999, 999},
             	 	 {999, 999, 0, 7, 1},
             	 {999, 6, 999, 0, 9},
       	       	 {6, 2, 999, 999, 0}};




int camino (int T[], int v){

    int iContador = 0;

    if (T[v] != 1){
        iContador = camino(T, T[v]);
        cout << "-" << T[v];
        iContador++;
    }

    return iContador;
}

void dijkstra (int W[5][5]){

  int L[tam+1], T[tam+1], R[tam+1], min, vmin;

  for (int i = 2; i<=tam; i++){
    L[i] = W[0][i-1];
    T[i] = 1;
  }

    for (int x = 1; x < tam; x++){
      min = 999;

      for (int i = 2; i<= tam; i++)

        if ( 0 <= L[i] && L[i] <= min){
          min = L[i];  vmin = i;
        }

      for (int i=2; i<= tam; i++)

        if (L[vmin]+W[vmin-1][i-1] < L[i]){
          L[i] = L[vmin]+W[vmin-1][i-1];
          T[i] = vmin; }
          R[vmin] = L[vmin];
          L[vmin] = -1;
        }


      cout << "\nCAMINOS MAS CORTOS\n";

      for (int i = 2; i <= tam; i++){
          cout << "de 1 a " << i << ": 1";
          camino(T, i);
          cout << "-" << i << " cuesta " << R[i] - 1 << " unidades\n";
      }
  }


void rellenaMatriz(int arr[5][5], int n){

    int infinito = 99;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == infinito){
                arr[i][j] = 99;
            }

            else if(arr[i][j] > 0 && arr[i][j] < infinito){
                arr[i][j] = 1;
            }
        }
    }
}


void printMatrix5(int arr[5][5], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << '\t';
        }

        cout << endl;
    }
}

 void dijkstra2 (int W[5][5]){

    int L[tam+1], T[tam+1], R[tam+1], min, vmin;
    int iContador  = 0;

    for (int i = 2; i<=tam; i++){
      L[i] = W[0][i-1];
      T[i] = 1;
    }

      for (int x = 1; x < tam; x++){
        min = 999;

        for (int i = 2; i<= tam; i++)

          if ( 0 <= L[i] && L[i] <= min){
            min = L[i];  vmin = i;
          }

        for (int i=2; i<= tam; i++)

          if (L[vmin]+W[vmin-1][i-1] < L[i]){
            L[i] = L[vmin]+W[vmin-1][i-1];
            T[i] = vmin; }
            R[vmin] = L[vmin];
            L[vmin] = -1;
          }


        cout << "\nCAMINOS MAS CORTOS\n";

        for (int i = 2; i <= tam; i++){
            cout << "de 1 a " << i << ": 1";
            iContador =  camino(T, i);
            cout << "-" << i << " cuesta " << R[i] << " unidades" << " escalas -> " << iContador << endl;;
        }
}


int minimo(int a, int b){

	if(a < b ){
		return a;
	}
	return b;
}

int floyd(int arr[5][5], int n){

	for(int k = 0; k < n; k++ ){
		for(int i = 0; i < n; i++ ){
			for(int j = 0; j < n; j++ ){
				minimo(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

/////PROBLEMA 3


int m = 3;  // cantidad de colores
int n = 9; // cantidad de estados (nodos)


int grafo[9][9] = {{0,1,1,0,0,0,0,0,0},
                    {1,0,1,1,1,0,0,0,0},
                    {1,1,0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,1,0,0},
                    {0,1,1,1,0,1,1,1,0},
                    {0,0,1,0,1,0,0,1,0},
                    {0,0,0,1,1,0,0,1,1},
                    {0,0,0,0,1,1,1,0,1},
                    {0,0,0,0,0,0,1,1,0}};


int vcolor[9+1]; //nodos + 1 (dummy)

bool valido(int i) {
    int j = 1;
    bool sw = true;

    while (j < i && sw){
        if ((grafo[i-1][j-1] && vcolor[i] == vcolor[j]) ) // 1 es true, 0 es false
            sw = false;
        j++;
    }
    return sw;
}


int coloreado (int i) {

    if (valido(i)){
        if (i == n && vcolor[1]!=4){
            cout << "-------------------------------------- \n";
            iContadorColores++;

            for (int x = 1; x <= n; x++){
                cout << "Nodo " << x << " se pinta del color #" << vcolor[x] << "\n";
            }

        }

        else{
            for(int color=1; color <= m; color++){
                vcolor[i+1] = color;
                coloreado(i+1);
            }
        }
    }

    return iContadorColores;
}



void printMatrix8(int arr[4][4], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << '\t';
        }

        cout << endl;
    }
}

int main(){

    //Problema 1
    // int myArr[7] = {7,1,5,3,6,2,4};
    // printArr(myArr, 7);
    // myHeapSort(myArr);
    // printArr(myArr, 7);

    //Problema 2
    // cout << endl << "dijstra 2" << endl;
    // printMatrix5(datos, 5);
    // rellenaMatriz(datos, 5);
    // cout << endl;
    // printMatrix5(datos, 5);
    // dijkstra(datos);

    //Probelma 3
    //cout << coloreado(0) << endl;

    printArr(col, 8);


    return 0;
}
