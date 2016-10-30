// Sergio Diaz - A01192313
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Cistern {

    int iDepth;
    int iHeight;
    int iWidth;
    int iFloorOffset;
    int iRelativeHeight;

    int getVolume(){ //volume in cubic meters
        return iDepth*iHeight*iWidth;
    }

    int getRelativeVolume(int h){ //volume in cubic meters
        return iDepth * h * iWidth;
    }

    int getRelativeHeight(){
        return iHeight + iFloorOffset;
    }

    int getFloorOffset(){
        return iFloorOffset;
    }

    // Constructor
    Cistern(int f, int d, int h, int w) : iFloorOffset(f), iDepth(d),
    iHeight(h), iWidth(w){}

    bool operator < (const Cistern& cist) const
    {
        return (iFloorOffset + iHeight < cist.iFloorOffset + cist.iHeight );
    }
};

struct smallest_offset{
    inline bool operator() (const Cistern& cist1, const Cistern& cist2){
        return (cist1.iFloorOffset < cist2.iFloorOffset);
    }
};

int userInput(vector<Cistern> &v, int quantityOfWater){

    int iCistNumber;
    int iDepth, iHeight, iWidth, iFloorOffset;

    cout << "# of cisterns --> ";
    cin >> iCistNumber;

    for (int i = 0; i < iCistNumber; i++) { //Se modifica el valor de cada cisterna

        cout << "Floor offset of cistern #" << i << " --> ";
        cin >> iFloorOffset;
        cout << "       Depth of cistern #" << i << " --> ";
        cin >> iDepth;
        cout << "      Height of cistern #" << i << " --> ";
        cin >> iHeight;
        cout << "       Width of cistern #" << i << " --> ";
        cin >> iWidth;

        Cistern temp(iFloorOffset, iDepth, iHeight, iWidth);

        v.push_back(temp);
    }

    //cout << "Total quantity of water to store in cubic meters --> ";
    cin >> quantityOfWater;

    return quantityOfWater;
}

void displayCisterns(vector<Cistern> &v){

    for (int i = 0; i < v.size(); i++) { //Se despliega el valor de cada cisterna

        cout << "Cistern #" << i << endl;
        cout << "       Depth --> " << v[i].iDepth << endl;
        cout << "      Height --> " << v[i].iHeight << endl;
        cout << "       Width --> " << v[i].iWidth << endl;
        cout << "Floor offset --> " << v[i].iFloorOffset << endl;
        cout << "Max capacity --> " << v[i].getVolume() << endl;
        cout << endl;
    }
}


int systemHeight(vector<Cistern> &v){

    return v.back().iFloorOffset + v.back().iHeight;
}

void sortByFloorOffsetAndHeight(vector<Cistern> &v){

    sort(v.begin(), v.end());
}

int smallestOffset(vector<Cistern> &v){

    sort(v.begin(), v.end(), smallest_offset());

    return  v.front().iFloorOffset;
}


int bestCase(vector<Cistern> &v){

    int iSystemVolume;
    for (int i = 0; i < v.size(); i++) {

        iSystemVolume = iSystemVolume + v[i].getVolume();
    }

    return iSystemVolume;
}


////////////////////////////////////////////////////////////////////////////////

int getRelativeSystemVolume(vector<Cistern> &v, int iCurrentLevel){

    int iCurrentQuantityOfWater = 0;
    int iRealtiveHeight;

    //objective: iCurrentQuantityOfWater

    //llena cisternas que estan totalmente bajo la mitad o current level
    for(int i =0; i < v.size(); i++){

        if(v[i].getRelativeHeight() <= iCurrentLevel){

            iCurrentQuantityOfWater = iCurrentQuantityOfWater + v[i].getVolume();
        }
    }
    //llena cisternas que interesectan con middle
    for(int i =0; i < v.size(); i++){

        if(v[i].getFloorOffset() <= iCurrentLevel && v[i].getRelativeHeight() > iCurrentLevel){

            iRealtiveHeight = iCurrentLevel - v[i].getFloorOffset();
            iCurrentQuantityOfWater = iCurrentQuantityOfWater + v[i].getRelativeVolume(iRealtiveHeight);
        }
    }

    return iCurrentQuantityOfWater;
}

float fillCist(vector<Cistern> &v, int iLow, int iTop, int iDesiredQuantityOfWater, int iCurrentQuantityOfWater){

    float iCurrentLevel = (iTop + iLow) / 2;

    if (iLow > iTop) {
		iCurrentLevel = -1;

	} else {

        if(iDesiredQuantityOfWater == getRelativeSystemVolume(v, iCurrentLevel)){

            return iCurrentLevel;

        } else {

            if (iDesiredQuantityOfWater > getRelativeSystemVolume(v, iCurrentLevel)) {

                iCurrentLevel = fillCist(v, iCurrentLevel + 1, iTop, iDesiredQuantityOfWater, getRelativeSystemVolume(v, iCurrentLevel));

            } else{

                iCurrentLevel = fillCist(v,iLow, iCurrentLevel, iDesiredQuantityOfWater, getRelativeSystemVolume(v, iCurrentLevel));
            }
        }
    }

    return iCurrentLevel;
}

float getAnswer(float n){

    if(n == -1){
        cout << "OVERFLOW" << endl;
    } else {

        cout << setprecision (2) << fixed << n;
    }

    return n;
}


void clearVector(vector<Cistern> v){

    while(!v.empty()){
        v.pop_back();
    }
}

//Calcula un nuevo sistema
 vector<Cistern> newSystem(vector<Cistern> v){

    float answer;
    int quantityOfWater = userInput(v, quantityOfWater);
    sortByFloorOffsetAndHeight(v);
    int iSystemHeight = systemHeight(v);
    int iLowestSystemOffeset = smallestOffset(v);
    displayCisterns(v);
    answer = fillCist(v, iLowestSystemOffeset, iSystemHeight, quantityOfWater, 0);
    getAnswer(answer);

    return v;
}
//Calcula un nuevo nivel para un sistema que del que ya se tienen los datos
void oldSystem (vector<Cistern> v, int newQuantityOfWater){

    float answer;
    displayCisterns(v);
    answer = fillCist(v, smallestOffset(v), systemHeight(v), newQuantityOfWater, 0);
    getAnswer(answer);
}


int main() {

    vector<Cistern> vecCisterns;
    vector<Cistern> vecAux;
    vecAux = newSystem(vecCisterns);

    int newQuantityOfWater;

    char userAns;
    cout << endl;
    cout << "Quiere hacer otro cálculo? (y/n)" << endl;
    cin >> userAns;

    while(userAns != 'n'){

        char userAns2;
        cout << endl;
        cout << "Con el mismo sistema? (y/n)" << endl;
        cin >> userAns2;

        if(userAns2 == 'n'){
            clearVector(vecCisterns);
            newSystem(vecCisterns);
            vecAux = newSystem(vecCisterns);
            cout << endl;

        } else {
            cout << "Introduzca la nueva cantidad de agua" << endl;
            cin >> newQuantityOfWater;
            oldSystem(vecAux, newQuantityOfWater);
            cout << endl;
        }

        char userAns;
        cout << endl;
        cout << "Quiere hacer otro cálculo? (y/n)" << endl;
        cin >> userAns;
    }
}

//caso de prueba
/*
4
11 1 7 5
15 2 6 2
19 1 4 8
5 1 8 5
78
*/
