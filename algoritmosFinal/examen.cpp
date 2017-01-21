//A01192313
//Sergio Diaz
//SI FUNCIONA :D

#include <iostream>
using namespace std;

int distancias[15][15] =
{{0, 9999, 9999, 9999, 276, 9999, 9999, 321, 9999, 9999, 59, 9999, 9999, 9999, 9999},
{9999, 0, 542, 9999, 9999, 134, 9999, 9999, 9999, 9999, 9999, 164, 9999, 9999, 9999},
{9999, 542, 0, 9999, 9999, 9999, 9999, 9999, 1048, 9999, 9999, 9999, 9999, 9999, 9999},
{9999, 9999, 9999, 0, 150, 9999, 9999, 9999, 9999, 872, 9999, 9999, 9999, 9999, 85},
{276, 9999, 9999, 150, 0, 125, 178, 200, 543, 321, 765, 342, 111, 90, 999},
{9999, 134, 9999, 9999, 125, 0, 9999, 9999, 9999, 9999, 9999, 9999, 631, 9999, 9999},
{9999, 9999, 9999, 9999, 178, 9999, 0, 722, 43, 9999, 9999, 9999, 9999, 892, 9999},
{321, 9999, 9999, 9999, 200, 9999, 722, 0, 277, 9999, 9999, 9999, 9999, 9999, 722},
{9999, 9999, 1048, 9999, 543, 9999, 43, 277, 0, 9999, 9999, 421, 9999, 9999, 9999},
{9999, 9999, 9999, 872, 321, 9999, 9999, 9999, 9999, 0, 25, 9999, 50, 9999, 100},
{59, 9999, 9999, 9999, 765, 9999, 9999, 9999, 9999, 25, 0, 9999, 9999, 175, 9999},
{9999, 164, 9999, 9999, 342, 9999, 9999, 9999, 421, 9999, 9999, 0, 9999, 9999, 501},
{9999, 9999, 9999, 9999, 111, 631, 9999, 9999, 9999, 50, 9999, 9999, 0, 453, 9999},
{9999, 9999, 9999, 9999, 90, 9999, 892, 9999, 9999, 9999, 175, 9999, 453, 0, 9999},
{9999, 9999, 9999, 85, 999, 9999, 9999, 722, 9999, 100, 9999, 501, 9999, 9999, 0}};


int tam = 15;

//variabeles

const float costoXkilometro = 0.01;
const float costoXLogistica = 0.10;
const float impuestoAlExtranjero = 0.20;
const int TRESHHOLD = 1000; //1000 km para cobro al extranjero


float total = 0;
int ciudadesIntermedias = 0;
float impuesto;


int minimo(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}

//Floyd
void floyd(int p[15][15], int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                p[i][j] = minimo(p[i][j], p[i][k] + p[k][j]);



}

void printMatrix(int mat[15][15], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }
}

//Camino
void camino(int T[], int v){
    if(T[v] != 1){
        ciudadesIntermedias++;
        camino(T, T[v]);
        cout << "-" << T[v];
    }
}

//Dijsktra
// void dijsktra(int W[15][15]){
//     int L[tam+1], T[tam+1], R[tam + 1], min, vmin;
//
//     for(int i = 2; i<= tam; i++){
//         L[i] = W[0][i-1];
//         T[i] = 1;
//     }
//
//     for(int x = 1; x < tam; x++){
//         min = 9999;
//         for(int i = 2; i<=tam; i++){
//             if(0 <= L[i] && L[i] <= min){
//                 min = L[i];
//                 vmin = i;
//             }
//         }
//
//         for(int i = 1; i <= tam; i++){
//             if(L[vmin]+W[vmin-1][i-1]<L[i]){
//                 L[i] = L[vmin]+W[vmin-1][i-1];
//                 T[i]=vmin;
//             }
//         }
//
//         R[vmin]= L[vmin];
//         L[vmin]= -1;
//     }
//
//     cout << "\n Caminos mas cortos \n";
//     for(int i = 2; i <= tam; i++){
//         cout << "de 1 a " << i << " :1";
//         camino(T,i);
//         cout << "-" << i << " cuesta " << R[i] << "unidades \n";
//     }
//
// }

float cobroXkilometro(int n){
    return n*costoXkilometro;
}

float cobroXLogistica(int n){
    return n*costoXLogistica;
}

float cobroServicioExtranjero(float n){
    return n*impuestoAlExtranjero;
}

float costoTotal(float costoPorKM, float costoLogistica, float costoExtranjero){
    return costoPorKM + costoLogistica + costoExtranjero;
}

//Dijsktra
void dijsktra2(int W[15][15], int whichNode, int fin){
    int L[tam+1], T[tam+1], R[tam + 1], min, vmin;

    float tax = 0;

    for(int i = 0; i<= tam; i++){
        L[i] = W[whichNode][i-1];
        T[i] = 1;
    }

    for(int x = 1; x < tam; x++){
        min = 9999;
        for(int i = 2; i<=tam; i++){
            if(0 <= L[i] && L[i] <= min){
                min = L[i];
                vmin = i;
            }
        }
        for(int i = 2; i <= tam; i++){
            if(L[vmin]+W[vmin-1][i-1]<L[i]){
                L[i] = L[vmin]+W[vmin-1][i-1];
                T[i]=vmin;
            }
        }
        R[vmin]= L[vmin];
        L[vmin]= -1;
    }

    for(int i = 1; i <= tam; i++){
        //if(i+1 != whichNode && (fin == i)){
        //if(i+1 != whichNode){
        if(i != whichNode && (fin == i-1)){
            cout << "Ruta de: " << whichNode << " a " << i-1 << " -> " << whichNode;
            camino(T,i);
            cout << "-" << i-1 << endl;
            cout << "Costo por KM: " << cobroXkilometro(R[i]) << " pesos \n";
            cout << "Costo por logistica de otras ciudades: " <<  cobroXLogistica(ciudadesIntermedias) << " pesos \n";

            if(R[i] > TRESHHOLD){
                tax = impuestoAlExtranjero;
            } else{
                tax = 0;
            }
            cout << "Costo por envio al extranjero: " <<  cobroServicioExtranjero(tax) << " pesos \n";
            cout << "Costo total: " <<  costoTotal(cobroXkilometro(R[i]),cobroXLogistica(ciudadesIntermedias),cobroServicioExtranjero(tax)) << " pesos \n";
            cout << endl;
            ciudadesIntermedias = 0;
        }
    }
}





int main() {

    int ciudadInicio;
    int ciudadFin;
    string input;
    ciudadInicio = 3;
    ciudadFin = 3;



    //dijsktra2(distancias,ciudadInicio, ciudadFin);



    cout << "Desea hacer un envio? (s/n)" << endl;
    cin >> input;

    while(input == "s"){
        cout << "Ciudad inicio -> ";
        cin >> ciudadInicio;
        cout << endl << "Ciudad fin -> ";
        cin >> ciudadFin;
        cout << endl;


        dijsktra2(distancias,ciudadInicio, ciudadFin);


        cout << "Desea hacer otro un envio? (s/n)" << endl;
        cin >> input;

    }

    //floyd(distancias,15);
    //printMatrix(distancias,15);

}
