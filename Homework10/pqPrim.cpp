//Sergio Díaz
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//Dato del problema.
int grafo[15][15] = {{0, 2, 3, 2, 999, 4, 5, 2, 9, 999, 3, 2, 999, 5, 6}, {2, 0, 2, 8, 999, 5, 999, 4, 6, 999, 8, 2, 3, 4, 1}, {3, 2, 0, 1, 6, 3, 999, 5, 6, 1, 999, 4, 2, 7, 999},
    {2, 8, 1, 0, 1, 6, 1, 3, 3, 3, 999, 8, 1, 4, 999}, {999, 999, 6, 1, 0, 999, 1, 4, 1, 999, 3, 1, 999, 1, 999},{4, 5, 3, 6, 999, 0, 999, 7, 1, 7, 6, 999, 2, 7, 4},
    {5, 999, 999, 1, 1, 999, 0, 4, 1, 4, 7, 4, 999, 1, 5}, {2, 4, 5, 3, 4, 7, 4, 0, 2, 999, 4, 999, 1, 4, 1}, {9, 6, 6, 3, 1, 1, 1, 2, 0, 9, 1, 2, 3, 6, 4},
    {999, 999, 1, 3, 999, 7, 4, 999, 9, 0, 4, 999, 999, 6, 2}, {3, 8, 999, 999, 3, 6, 7, 4, 1, 4, 0, 4, 2, 999, 4}, {2, 2, 4, 8, 1, 999, 4, 999, 2, 999, 4, 0, 7, 2, 999},
    {999, 3, 2, 1, 999, 2, 999, 1, 3, 999, 2, 7, 0, 7, 4}, {5, 4, 7, 4, 1, 7, 1, 4, 6, 6, 999, 2, 7, 0, 8}, {6, 1, 999, 999, 999, 4, 5, 1, 4, 2, 4, 999, 4, 8, 0}
};

struct nodosArcos{
    int verticeIni; int verticeFin; int peso;
    bool operator<(const nodosArcos& x) const{ return peso > x.peso;}
};
void camino (int T[], int v){
    if (T[v] != 0){
        camino(T, T[v]);
        cout << "-" << T[v]+1;
    }
}
void Dijkstra (int W[15][15], bool vertices[], priority_queue<nodosArcos> &myPQueue, int caminos[], int nodo ){
    int tam=15; int x=nodo-1; int ruta[tam]; ruta[nodo-1]=0; int resultados[tam];
    int caminosCreados=0; nodosArcos nodTemp; int filacont=0;
    int arcoFinal, arcoInicial, arcoPeso;
    for(int i=0; i<tam; i++){
        if(i!=x){
            nodTemp.verticeIni=x; nodTemp.verticeFin=i; nodTemp.peso=caminos[x]+W[x][i];
            myPQueue.push(nodTemp); filacont++;
        }
    }
        arcoFinal=myPQueue.top().verticeFin; arcoInicial=myPQueue.top().verticeIni;
        arcoPeso=myPQueue.top().peso; caminosCreados++; caminos[arcoFinal]=arcoPeso;

    while(caminosCreados<tam){
        arcoFinal=myPQueue.top().verticeFin; arcoInicial=myPQueue.top().verticeIni;
        arcoPeso=myPQueue.top().peso; x=arcoFinal;
        if(!vertices[arcoFinal])
            myPQueue.pop();
        if(vertices[arcoFinal]){
            caminosCreados++; caminos[arcoFinal]=arcoPeso; ruta[arcoFinal]=arcoInicial;
            resultados[arcoFinal]=arcoPeso; vertices[arcoFinal]=false; myPQueue.pop();
            for(int i=0; i<tam; i++){
                if(x!=i||vertices[i]){
                    nodTemp.verticeIni=x; nodTemp.verticeFin=i;
                    nodTemp.peso=caminos[x]+W[x][i];
                    myPQueue.push(nodTemp);
                }
            }
        }
    }
    for (int i = 0; i < tam; i++){
        if(i!=nodo-1){
            if(nodo==1)
                cout << "de "<<nodo<<" a " << i+1 << ": 1";
            else
               cout << "de "<<nodo<<" a " << i+1 << ": ";
            camino(ruta, i);
            cout << "-" << i+1 << " cuesta " << resultados[i] << " unidades\n";
        }
    }
}

int main() {
    priority_queue<nodosArcos> myPQueue;
    int nodo;
    int caminos[15];
    bool vertices[15];
    cout<<"Desde que nodo quiere partir?"<<endl;
    cin>>nodo;
    //Inicializar los nodos que he utilizado.
    for(int i=0; i<15; i++){
        if(nodo-1==i){
            vertices[i]=false;
            caminos[i]=0;
        }
        else{
            vertices[i]=true;
            caminos[i]=0;
        }
    }
    Dijkstra(grafo, vertices, myPQueue, caminos, nodo);
    return 0;
}
