#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>
#include <limits>
#include <cmath>

//Sergio Díaz - A01192313
//Adrían Peña - A00816456
//Tarea #6
//Fecha de entrega: 7 de octubre del 2016
//Profesor: Román Martinez
//Materia: Análisis y diseño de algoritmos
//El programa considera los planetas con mismo valor y despliega todos los mayores en orden alfabético

using namespace std;

struct planeta
{
    char cId;
    float fValor;
    string sConexiones;

};

struct galaxia
{
    planeta pPlanetas[26];
    int iNumeroPlanetas;
};

//initializes matrix with 100 in all spaces except in the main diagonal (with zeroes)
void initializesTradingMatrix(int arr[][27])
{

    int iN = 27;

    for(int iI = 0; iI < iN; iI++)
    {
        for(int iJ = 0; iJ < iN; iJ++)
        {

            if(iJ == iI)
            {
                arr[iI][iJ] = 0;
            }
            else
            {
                arr[iI][iJ] = 100;
            }
        }
    }
}

void printMatrix27(int arr[][27])
{

    int iN = 27;

    for(int iI = 0; iI < iN; iI++)
    {
        for(int iJ = 0; iJ < iN; iJ++)
        {
            cout << arr[iI][iJ] << ' ';
        }
        cout << endl;
    }
}

int getAscii(char s)
{

    return s - 65;
}

void floyd(int arr[][27])
{

    int iN = 27;

    for(int iK = 0; iK < iN; iK++)
    {

        for(int iI = 0; iI < iN; iI++)
        {

            for(int iJ = 0; iJ < iN; iJ++)
            {
                arr[iI][iJ] = min(arr[iI][iJ], arr[iI][iK]+ arr[iK][iJ]);
            }
        }
    }
}

double tax(double currentValue)
{

    return currentValue * .95;
}

void costoDeExportacion(int arr[][27], galaxia gal)
{
    char arrId[26];
    float arrValorMaximo[26];
    int cont=0;

    for (int i = 0; i < gal.iNumeroPlanetas; i++)
    {

        arrValorMaximo[i] = gal.pPlanetas[i].fValor;

        arr[getAscii(gal.pPlanetas[i].cId)][26]--;

        if(arr[getAscii(gal.pPlanetas[i].cId)][26] < 99)
        {

            for(int j = 0; j < arr[getAscii(gal.pPlanetas[i].cId)][26]; j++)
            {

                arrValorMaximo[i] = tax(arrValorMaximo[i]);
            }
        }
    }

    float iMayor = 0;
    int iIndice = 0;

    for(int i = 0; i < gal.iNumeroPlanetas; i++)
    {

        if(iMayor <= arrValorMaximo[i])
        {
            iMayor = arrValorMaximo[i];
            iIndice = i;
        }

    }

    for(int i = 0; i < gal.iNumeroPlanetas; i++)
    {

        if(iMayor == arrValorMaximo[i])
        {
            arrId[cont]=gal.pPlanetas[i].cId;
            cont++;
        }

    }

    std::sort(arrId, arrId+cont);

    for(int i=0; i<cont; i++)
    {
        cout << "Import from " << arrId[i] << endl;
    }


}

int main()
{
    int iAdy[27][27];
    ifstream archivo;
    int iNumPlanetas=0, iCont=0;
    galaxia gGalaxias[300];
    archivo.open("datos.txt");

    //Lee el archivo linea por linea y mete el código a un arreglo.
    while (!archivo.eof())
    {
        archivo >> iNumPlanetas;
        gGalaxias[iCont].iNumeroPlanetas=iNumPlanetas;
        for(int i=0; i<iNumPlanetas; i++)
        {
            archivo>>gGalaxias[iCont].pPlanetas[i].cId;
            archivo>>gGalaxias[iCont].pPlanetas[i].fValor;
            archivo>>gGalaxias[iCont].pPlanetas[i].sConexiones;
        }
        iCont++;
    }
    archivo.close();


    for(int i=0; i<iCont; i++) //Itera sobre galaxias.
    {
        //Inicializamos la matriz de adyacencia con 0 en diagonal principal y 100 en lo demas.
        initializesTradingMatrix(iAdy);

        for(int j=0; j<gGalaxias[i].iNumeroPlanetas; j++)
        {
            for(int k=0; k<gGalaxias[i].pPlanetas[j].sConexiones.length(); k++)
            {
                //Checamos si tiene conexion con la tierra
                if(gGalaxias[i].pPlanetas[j].sConexiones[k]=='*')
                    iAdy[getAscii(gGalaxias[i].pPlanetas[j].cId)][26]=1;

                else
                    iAdy[getAscii(gGalaxias[i].pPlanetas[j].cId)][getAscii(gGalaxias[i].pPlanetas[j].sConexiones[k])]=1;

            }
        }
        floyd(iAdy);
        costoDeExportacion(iAdy, gGalaxias[i]);
    }


    return 0;
}
