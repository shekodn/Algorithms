// Sergio Diaz - A01192313
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Cistern {

    int iDepth;
    int iHeight;
    int iWidth;
    int iFloorOffset;
    int iRelativeHeight;
    bool bFull = false;
    int iCurrentVolume = 0;

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

    bool isFull(){
        return bFull;
    }

    int getCurrentVolume(){
        return iCurrentVolume;
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

        //Cistern temp(iFloorOffset, iDepth, iHeight, iWidth);
        Cistern temp(iFloorOffset, iDepth, iHeight, iWidth);

        v.push_back(temp);
    }


    cout << "Total quantity of water to store in cubic meters --> ";
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


bool quantityOfWater(){

    bool bOverflow = true;



    return bOverflow;
}

void deleteCisterns(vector<Cistern> &v){

    while (!v.empty()){
        //delete v.back();
        v.pop_back();
    }
}


int systemHeight(vector<Cistern> &v){

    return v.back().iFloorOffset + v.back().iHeight;
}


int systemVolume(vector<Cistern> &v){

}

void sortByFloorOffsetAndHeight(vector<Cistern> &v){

    sort(v.begin(), v.end());
}

int smallestOffset(vector<Cistern> &v){

    sort(v.begin(), v.end(), smallest_offset());

    return  v.front().iFloorOffset;
}

bool overflow(vector<Cistern> &v, int &iCantAgua){

    int iSystemVolume = 0;
    cout << endl;

    for (int i = 0; i < v.size(); i++) {

        iSystemVolume = iSystemVolume + v[i].getVolume();
    }

    if(iCantAgua > iSystemVolume){

        cout << "overflow" << endl;
        cout << endl;
        return true;
    }

    cout << "no overflow" << endl;
    cout << endl;

    return false;
}

int bestCase(vector<Cistern> &v){

    int iSystemVolume;
    for (int i = 0; i < v.size(); i++) {

        iSystemVolume = iSystemVolume + v[i].getVolume();
    }

    return iSystemVolume;
}

int getRelativeSystemVolume(int iMiddle, vector<Cistern> &v,int iWaterQuantity, int iCounter){

    int iMaxWaterHeight = 0;
    int iWater = 0;
    int i = iCounter;

    //llena cisternas que estan totalmente bajo la mitad
    while(v[i].getRelativeHeight() <= iMiddle && !v[i].isFull()) {
        iWater = iWater + v[i].getVolume();
        v[i].bFull = true;
        //iMaxWaterHeight = v[i].getRelativeHeight();
        cout << "VOL" << v[i].getVolume() << endl;

        i++;
    }

    cout << "i water" << iWater << endl;
    cout << "contador " << i << endl;


    //llena cisternas que interesectan con middle
    while(v[i].getRelativeHeight() <= iMiddle && !v[i].isFull()) {
        iWater = iWater + v[i].getRelativeVolume(iMiddle - v[i].getFloorOffset());
        i++;
        cout << "VOL PARCIAL" << v[i].getVolume() << endl;

    }

    cout << "i water" << iWater << endl;



    return iWaterQuantity - iWater;


}

int fillCist(vector<Cistern> &v, int iLow, int iTop, int quantityOfWater){

    int iMiddle = (iTop + iLow) / 2;
    int iCounter = 0;
    int iMaxWaterHeight = iLow;

    cout << "mid " << iMiddle << endl;

    if (iLow > iTop ) {

		iMaxWaterHeight = -1;

        cout << "111";
        cout << "mid " << iMiddle << endl;



	} else {

        int iMiddle = (iTop + iLow) / 2;

		if((getRelativeSystemVolume(iMiddle, v, quantityOfWater, iCounter)) == quantityOfWater){

            cout << getRelativeSystemVolume(iMiddle, v, quantityOfWater, iCounter) << endl;
            cout << quantityOfWater << endl;
            iCounter++;


			iMaxWaterHeight = iMiddle;
            cout << "222 ";
            cout << "mid " << iMiddle << endl;



		}  else {

			if ((getRelativeSystemVolume(iMiddle, v, quantityOfWater, iCounter)) > quantityOfWater) {

				iMaxWaterHeight = fillCist(v, iLow, iMiddle, quantityOfWater);
                cout << "333 ";
                cout << "mid " << iMiddle << endl;
                iCounter++;



			} else {

				iMaxWaterHeight = fillCist(v, iMiddle + 1, iTop, quantityOfWater);
                cout << "444 ";
                cout << "mid " << iMiddle << endl;
                iCounter++;



			}
		}
	}

    return iMaxWaterHeight;
}


int main() {

    vector<Cistern> vecCisterns;
    int quantityOfWater = userInput(vecCisterns, quantityOfWater);

    cout << "Desired quantity of water --> " << quantityOfWater << endl;

    sortByFloorOffsetAndHeight(vecCisterns);

    int iSystemHeight = systemHeight(vecCisterns);
    int iLowestSystemOffeset = smallestOffset(vecCisterns);

    cout << "    System Height --> " << systemHeight(vecCisterns) <<  endl;
    cout << " System begins in --> " << smallestOffset(vecCisterns) <<  endl;

    overflow(vecCisterns, quantityOfWater);
    displayCisterns(vecCisterns);
    cout << "quantity of water" << quantityOfWater << endl;
    int answer = fillCist(vecCisterns, iLowestSystemOffeset, iSystemHeight, quantityOfWater);

    cout << "Answer " << answer << endl;

    //caso de prueba
    /*
    4
    11 1 7 5
    15 2 6 2
    19 1 4 8
    5 1 8 5
    78
    */

}
