#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// int n = 6; // cantidad de objetos
// int VALOR = 21; //valor que se busca
// int obj[6] = {0,5,6,10,11,16};
// int include[6] = {0,0,0,0,0,0};
// int T = 0 + 5 + 6 + 10 + 11 + 16;


string estados[51] = {"California", "Texas", "Nueva York", "Florida", "Pensilvania", "Illinois",
"Ohio", "Georgia", "Michigan", "Carolina del Norte", "Nueva Jersey", "Virginia", "Washington",
"Arizona", "Tennessee", "Indiana", "Massachusetts", "Minnesota", "Missouri", "Wisconsin"
"Maryland", "Alabama", "Carolina del Sur", "Colorado", "Kentucky", "Luisiana", "Connecticut",
"Oklahoma", "Oregon", "Mississippi", "Arkansas", "Nevada", "Utah", "Iowa", "Kansas", "Nebraska",
"Nuevo Mexico", "Virginia Occidental", "Nuevo Hampshire", "Hawaii", "Rhode Island", "Idaho",
"Maine", "Alaska", "Montana", "Delaware", "Dakota del Norte", "Dakota del Sur", "Vermont",
"Wyoming", "Washington D.C. "};


int VALOR = 270; //valor que se busca


//Revisar si deben estar acomodados asc o desc
int obj[51] = {55, 38, 29, 29, 20, 20, 18, 16, 16, 15, 14, 13, 12, 11, 11, 11, 11, 10, 10, 10, 10,
9, 9, 9, 8, 8, 7, 7, 7, 6, 6, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3};

int n = 51; // cantidad de estados
//int VALOR = 270; //valor que se busca para ganar

//respuestas -> dummy + n
int include[52] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int T = 538; // valor maximo (suma de todos los estados)


void sum_of_subsets (int i, int acum, int total){

    if (acum+total>=VALOR &&   (acum == VALOR || acum+obj[i+1] <= VALOR)  ){

        if (acum==VALOR){
            for(int k=1; k<=n; k++) {
                cout << include[k];

            }
            cout << endl;
        }

        else{
            include[i+1] = 1;
            sum_of_subsets(i+1, acum+obj[i+1], total-obj[i+1]);
            include[i+1] = 0;
            sum_of_subsets(i+1, acum, total - obj[i+1]);
        }
    }
}



int main(){


    // solucion esperada
    // {obj1, obj2, obj3}
    // {obj1, obj5}
    // {obj3, obj4}

    sum_of_subsets(0,0,T);


    return 0;
}
