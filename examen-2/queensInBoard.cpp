#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;


int n = 8; // cantidad de reinas en el tablero

int iCont = 1;

//tablero vacio
int arrReinas[8][8] = { {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0} };

int col[8+1]; //numero de reinas + el dummy (es necesario)


void printMatrix8(int arr[8][8], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << '\t';
        }

        cout << endl;
    }
}

void resetMatrix(int arr[8][8], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }
}


bool cumple (int i){
    int k = 1;
    bool flag = true;
    while (k < i && flag){
        if ((col[i] == col[k] || abs(col[i]-col[k]) == i-k) )
            flag = false;
        k++;
    }

    return flag;
}

bool isAnswered = false; //el bool se usa para solo mostrar una solocion

void reinas(int i) {
    int j;

    if (cumple(i) && !isAnswered){

        if (i==n){
            //isAnswered = true;
            for(int k=1; k<=n; k++){
                cout << "Fila " << k << " columna " << col[k] << "\n";
                //arrReinas[k-1][col[k] - 1] = 1;

            }
            cout << "Solution " << iCont++ << endl;
            printMatrix8(arrReinas, 8);
            resetMatrix(arrReinas, 8);
            cout << endl;
        }
        else{
            for (j=1; j<=n; j++){
                col[i+1] = j;
                reinas(i+1);
            }
        }
    }
}



int main(){


    //printMatrix8(arrReinas, 8);
    reinas(0);
    //printMatrix8(arrReinas, 8);

    return 0;
}
