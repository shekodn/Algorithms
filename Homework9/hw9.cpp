#include <cstdlib>
#include <iostream>
#include <queue>
#include <array>
using namespace std;

///////////////////////////////////////////HEAP
void myHeapSort(int arr[]){
    priority_queue<int> mypq;
    int arrSize = sizeof(arr) - 1;
    //cout << "Arr size " << arrSize << endl;

    for(int i = 0; i < arrSize; i ++){
        mypq.push(arr[i]);
    }

    for(int i = arrSize - 1; i >= 0; i--){
        arr[i] = mypq.top();
        mypq.pop();
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

///////////////////////////////////////////Backtracking setup
int sumaArreglo(int arr[], int n){
    int iSuma = 0;
    for(int i = 0; i <= n; i++){
        iSuma = iSuma + arr[i];
    }
    return iSuma;
}

int rellenaArreglo(int arr[], int n){
    for(int i = 0; i <= n; i++){
        arr[i] = i;
    }
}

int rellenaArregloCeros(int arr[], int n){
    for(int i = 0; i <= n; i++){
        arr[i] = 0;
    }
}

int userInput(){
    int n;
    cout << "Type a number -> ";
    cin >> n;
    return n;
}

/////////////////////////////////////////////////////////Algorithm
//Global
int VALOR; //valor que se busca

void sum_of_subsets (int obj[], int include[], int i, int acum, int total, int input, int desiredValue){

    bool flag = false; //bool para controlar el signo de + y se imprima de manera bonita

    if (acum+total>=desiredValue &&   (acum == desiredValue || acum+obj[i+1] <= desiredValue)  ){
        if (acum==desiredValue){
            for(int k=1; k<=input; k++) {
                if(include[k] != 0){
                    if(!flag){
                        flag = true;
                        cout << k;
                    } else{
                        cout << " + " << k;
                    }
                }
            }
            cout << endl;
        }

        else{
            include[i+1] = 1;
            sum_of_subsets(obj, include, i+1, acum+obj[i+1], total-obj[i+1], input, desiredValue);
            include[i+1] = 0;
            sum_of_subsets(obj, include, i+1, acum, total - obj[i+1], input, desiredValue);
        }
    }
}


void problem1(){ //heap
    //Problema 1
    int myArr[7] = {7,1,5,3,6,2,4};
    cout << "Before sort: ";
    printArr(myArr, 7);
    myHeapSort(myArr);
    cout << " After sort: ";
    printArr(myArr, 7);

}

void problem2(){//backtracking

    //Problema 2
    int in = userInput(); //numero del usuario

    int arreglo[in];
    rellenaArreglo(arreglo, in); //relleno el arreglo de 0 hasta el input de user

    int respuestas[in];
    rellenaArregloCeros(respuestas, in); //relleno el arreglo con ceros para ver que respuestas incluir

    int Total = sumaArreglo(arreglo, in); //sumo cada elemento de arreglo para obtener el total
    sum_of_subsets (arreglo, respuestas, 0, 0, Total, in, in);
}


int main(){

    problem1();
    cout << endl;
    problem2();

    return 0;
}
