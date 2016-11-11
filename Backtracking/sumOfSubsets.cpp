#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n = 6; // cantidad de objetos
int VALOR = 21; //valor que se busca
int obj[6] = {0,5,6,10,11,16};
int include[6] = {0,0,0,0,0,0};
int T = 0 + 5 + 6 + 10 + 11 + 16;


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
