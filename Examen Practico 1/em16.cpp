//NOMBRE:
//MATR�CULA:

#include <cstdlib>
#include <iostream>

using namespace std;

const int TAM = 500;
const int N = 21;

int datos1[10] =   {0,1,4,5,6,7,9,10,14,22};
int misDatos[9] = {6,2,4,7,1,5,3,9,8};
int datos2[TAM] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 292, 295, 296, 297, 302, 304, 305, 306, 308, 311, 318, 319, 322, 323, 326, 328, 329, 331, 331, 338, 340, 346, 346, 347, 348, 354, 360, 366, 368, 369, 370, 371, 373, 377, 388, 392, 394, 398, 400, 401, 402, 405, 408, 412, 418, 429, 430, 436, 438, 441, 442, 443, 446, 447, 453, 459, 461, 463, 471, 472, 473, 474, 475, 478, 483, 490, 493, 496, 501, 502, 505, 507, 508, 510, 512, 516, 521, 526, 527, 534, 540, 543, 544, 547, 550, 551, 552, 556, 559, 560, 561, 564, 568, 575, 577, 578, 581, 583, 584, 585, 592, 594, 606, 610, 619, 622, 624, 625, 628, 630, 644, 646, 648, 661, 664, 672, 675, 682, 689, 690, 692, 693, 694, 698, 700, 703, 704, 711, 713, 716, 724, 728, 731, 740, 742, 745, 748, 749, 750, 751, 753, 761, 768, 769, 771, 774, 780, 782, 784, 787, 790, 791, 793, 803, 805, 808, 819, 820, 828, 829, 830, 831, 844, 847, 848, 849, 850, 851, 855, 860, 863, 868, 870, 872, 878, 885, 886, 892, 895, 898, 900, 909, 911, 912, 913, 919, 922, 924, 926, 933, 934, 939, 948, 950, 951, 953, 956, 961, 963, 964, 965, 969, 970, 976, 977, 978, 985, 993};
int datos3[TAM] = {809, 668, 633, 678, 517, 253, 15, 469, 464, 974, 862, 463, 56, 921, 354, 957, 937, 343, 588, 653, 139, 9, 383, 502, 465, 605, 937, 863, 951, 62, 81, 822, 298, 130, 564, 896, 43, 855, 541, 802, 675, 717, 285, 770, 159, 160, 156, 872, 336, 294, 733, 445, 946, 927, 110, 658, 470, 989, 159, 695, 577, 82, 149, 475, 968, 878, 381, 485, 382, 505, 741, 211, 959, 178, 543, 304, 835, 932, 150, 610, 511, 108, 306, 229, 60, 850, 79, 170, 952, 362, 697, 644, 517, 430, 646, 554, 705, 993, 895, 598, 327, 595, 46, 944, 743, 340, 239, 572, 802, 228, 664, 721, 502, 552, 782, 412, 882, 872, 844, 584, 180, 525, 538, 148, 350, 946, 130, 772, 751, 940, 423, 131, 935, 737, 66, 693, 979, 706, 900, 40, 281, 342, 566, 728, 227, 832, 495, 139, 501, 274, 123, 381, 758, 908, 154, 714, 481, 784, 81, 35, 683, 481, 923, 547, 913, 604, 673, 286, 44, 59, 362, 480, 238, 270, 558, 683, 3, 951, 397, 527, 96, 40, 785, 451, 212, 209, 96, 823, 36, 40, 211, 467, 273, 326, 432, 310, 298, 900, 130, 732, 450, 55, 885, 218, 45, 711, 130, 577, 320, 717, 883, 27, 693, 67, 681, 225, 123, 277, 885, 81, 401, 601, 289, 335, 476, 759, 678, 129, 446, 874, 634, 210, 553, 783, 779, 867, 955, 534, 933, 81, 898, 143, 858, 885, 568, 342, 743, 671, 580, 717, 942, 465, 154, 770, 742, 363, 638, 820, 642, 930, 622, 753, 477, 7, 250, 787, 722, 203, 872, 206, 431, 355, 915, 369, 137, 454, 182, 561, 944, 862, 718, 512, 308, 167, 938, 905, 242, 728, 644, 696, 454, 845, 713, 172, 960, 205, 638, 39, 286, 382, 52, 551, 409, 234, 150, 731, 19, 641, 372, 843, 410, 375, 160, 67, 392, 993, 782, 297, 772, 335, 860, 813, 175, 607, 724, 75, 91, 198, 325, 900, 760, 178, 936, 855, 363, 594, 331, 875, 373, 509, 423, 884, 166, 178, 547, 947, 891, 813, 464, 42, 249, 976, 456, 530, 706, 631, 35, 890, 594, 255, 23, 194, 621, 592, 583, 582, 83, 931, 659, 925, 183, 980, 220, 2, 635, 816, 142, 246, 127, 633, 665, 458, 676, 795, 677, 618, 802, 783, 919, 133, 674, 377, 440, 903, 740, 835, 658, 289, 929, 340, 912, 757, 351, 722, 433, 994, 899, 801, 246, 956, 889, 579, 966, 690, 663, 562, 900, 98, 829, 226, 138, 888, 174, 89, 938, 865, 227, 464, 534, 514, 417, 441, 444, 19, 930, 899, 966, 523, 50, 402, 364, 28, 975, 506, 624, 131, 390, 313, 200, 264, 978, 818, 544, 744, 406, 389, 152, 674, 668, 565, 557, 679, 183, 745, 140, 345, 978, 17, 651, 469, 820, 18, 714, 585, 129, 640, 489, 263, 283, 469, 583, 73, 740, 114, 486, 494, 937, 480, 499, 784, 899, 918, 158, 720, 957, 472, 753, 641, 494, 992};
float datos4[9] = {0, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125}; //la posici�n 0 no se ocupa.


//float datos41[9] = {1000, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, .125}; //la posici�n 0 no se ocupa.


// DEFINICIONES DE DATOS NECESARIOS PARA LAS PRUEBAS

// Problema 1
// Escribe aqui la implementaci�n del problema 1

int busqueda(int arr[10], int iInicio, int iFin){

    int iMiddle = (iInicio + iFin) / 2;
    int iIndice;
    cout << iMiddle << " " << arr[iMiddle] << endl;
    if (iInicio > iFin){
        return -1;
    } else {

        if(iMiddle  == arr[iMiddle]){
            return iMiddle;
            cout << "w" << endl;
        }

        if(iMiddle < arr[iMiddle]){

            iIndice = busqueda(arr, iInicio, iMiddle - 1);

        } else {
            iIndice = busqueda(arr, iMiddle + 1, iFin);
        }
    }

    return iIndice;
}

// Problema 2

// Funci�n para unir dos subarreglos ya ordenados
void une(int datos[], int inicio, int fin, int mitad)
{
    int i, j, k, aux[TAM];
    i = inicio;
    k = inicio;
    j = mitad + 1;
    while (i <= mitad && j <= fin)
    {
        if (datos[i] < datos[j])
        {
            aux[k] = datos[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = datos[j];
            k++;
            j++;
        }
    }
    while (i <= mitad)
    {
        aux[k] = datos[i];
        k++;
        i++;
    }
    while (j <= fin)
    {
        aux[k] = datos[j];
        k++;
        j++;
    }
    for (i = inicio; i < k; i++)
    {
        datos[i] = aux[i];
    }
}

// Funci�n recursiva para hacer el ordenamiento
void mergesort(int datos[], int inicio, int fin)
{

    int primerTercio;
    int segundoTercio;

    if (inicio < fin)
    {

        primerTercio = (fin-inicio)/3;
        segundoTercio = fin - primerTercio;

        mergesort(datos,inicio,inicio+primerTercio);
        mergesort(datos,inicio + primerTercio + 1, segundoTercio);
        une(datos,inicio,segundoTercio,inicio + primerTercio);
        mergesort(datos,segundoTercio+1, fin);
        une(datos,inicio,fin, segundoTercio);
    }
}
//Problema 3
// Algoritmo de Gilbert y Moore

// inicio LUCIANA


float minimo(int i, int j, float A[N][N])
{
	// implementaci�n a resolver en el problema 3
    // A[i,k-1] + A[k+1, j] para k desde i hasta j.
    float minimo  = 555;
    for(int k = i; k <= j; k++){

        // A[i,k-1] + A[k+1, j] para k desde i hasta j.

        if(A[i][k-1]+ A[k+1][j] < minimo){
            minimo = A[i][k-1]+ A[k+1][j];
        }
    }

    return minimo;
}

float sumatoria(int i, int j, float p[])
{
	// implementaci�n a resolver en el problema 3
    // La sumatoria calcula la suma de las probabilidades de la llave i hasta j

    float sumatoria = 0;

    for (int k = i; k <= j; k++){
        sumatoria = sumatoria + p[k];
    }

    return sumatoria;
}


float gilbertymoore (float p[], int n)
{
	float A[N][N], R[N][N];
	// se considera que se usar�n la columnas 0 a n y los renglones 1 a n+1 en la matriz
	int j;

	for (int i = 1; i<= n; i++)
	{
		A[i][i-1] = 0; A[i][i] = p[i];
  		R[i][i] = i; R[i][i-1] = 0;
	}
	A[n+1][n] = 0;
	R[n+1][n] = 0;

	for (int diag = 1; diag <= n-1; diag++){
	  for (int i = 1; i <= n-diag; i++)
		{
			j = i+diag;
            A[i][j] = minimo(i, j, A) + sumatoria(i, j, p); //funciona
			// calcula el valor m�nimo entre los diversos valores de:
			// A[i,k-1] + A[k+1, j] para k desde i hasta j.
			// La sumatoria calcula la suma de las probabilidades de la llave i hasta j
		}
    }
	//return A[1][7];
    return A[1][n];

}


// fin LUCIANA


void printarr9(int arr[9]){

    for(int i = 0; i < 9; i++){

        cout << arr[i] << " ";
    }
    cout << endl;

}

void printarr500(int arr[500]){

    for(int i = 0; i < 500; i++){

        cout << arr[i] << " ";
    }
    cout << endl;

}

void printranges(int arr[10], int inicio, int fin){

    for(int i = inicio; i <= fin; i++){

        cout << arr[i] << " ";
    }

    cout << endl;
}

int binarySearch(int arr[], int inicio, int fin, int number){

    int mitad;
    int index;

    mitad = (inicio + fin)/2;

    if(inicio > fin){
        return -1;
    }
    else{

        if(number == arr[mitad]){
            return mitad;
        } else {
            if(arr[mitad] > number){
                index = binarySearch(arr,inicio, mitad-1 ,number);
            }
            else{
                index = binarySearch(arr,mitad + 1, fin ,number);
            }
        }
    }

    return index;
}


int fibor(int n){
    if(n < 1){
        return 0;
    } else{
        if(n < 2){
            return n;
        } else{
            return fibor(n-1) + fibor(n-2);
        }
    }
}



int main()
{
    //Escribe aqui las llamadas para probar y responder preguntas del examen
	//system("pause");
    //cout << busqueda(datos2, 0, 499) << endl;

    /*
    //int datos1[10] =   {0,1,4,5,6,7,9,10,14,22};
    cout << binarySearch(datos1,0,9,0) << endl;
    cout << binarySearch(datos1,0,9,1) << endl;
    cout << binarySearch(datos1,0,9,4) << endl;
    cout << binarySearch(datos1,0,9,5) << endl;
    cout << binarySearch(datos1,0,9,6) << endl;
    */


    // imicio LUCIANA
    //Importante, si quieres 16 datos tu array es de 17 porque la primera posicion debe ser 0
    float datoLuciana[17] = {0, 0.2, 0.40, 0.10, 0.30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //la posici�n 0 no se ocupa.
    int NumeroDeArreglo = 4; //Numero de nodos en tu caso de entrada, la probabilidad la tienes que dividir entre 100 (40 va a ser .4) USA FLOATS!
    cout << gilbertymoore(datoLuciana, NumeroDeArreglo) << endl;


    // fin LUCIANA




    /*
    printarr500(misDatos);
    mergesort(misDatos,0,499);
    cout << "Algoritmo ordenado" << endl;
    printarr500(misDatos);
    */


/*
    int num = 5;

    cout << fibor(1) << endl;
    cout << fibor(2) << endl;
    cout << fibor(3) << endl;
    cout << fibor(4) << endl;
    cout << fibor(5) << endl;
    cout << fibor(6) << endl;
    cout << fibor(7) << endl;
    cout << fibor(8) << endl;

    */









}
