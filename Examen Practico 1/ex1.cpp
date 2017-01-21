//Nombre:
//Matr�cula:

#include <cstdlib>
#include <iostream>

using namespace std;

int ventas[365] = { 485, 487, 494, 495, 501, 504, 512, 519, 522, 523, 530, 533, 534, 535, 538, 546, 547, 555, 559, 562, 565, 566, 572, 580, 586, 591, 595, 602, 607, 610, 617, 625, 632, 638, 646, 652, 657, 661, 665, 671, 673, 677, 681, 685, 689, 690, 697, 698, 704, 710, 712, 719, 722, 730, 734, 742, 750, 751, 752, 756, 764, 771, 778, 783, 788, 796, 800, 805, 811, 814, 819, 826, 827, 828, 832, 833, 839, 844, 848, 852, 857, 862, 870, 878, 882, 890, 894, 901, 902, 903, 905, 908, 916, 921, 928, 936, 944, 952, 955, 962, 963, 971, 978, 984, 988, 989, 993, 997, 1001, 1006, 1007, 1010, 1016, 1018, 1024, 1026, 1029, 1031, 1034, 1036, 1044, 1045, 1052, 1058, 1066, 1067, 1068, 1076, 1077, 1083, 1090, 1094, 1099, 1104, 1109, 1117, 1121, 1124, 1125, 1131, 1134, 1137, 1139, 1142, 1144, 1146, 1149, 1152, 1151, 1148, 1145, 1144, 1143, 1140, 1139, 1137, 1135, 1132, 1130, 1129, 1128, 1127, 1126, 1125, 1122, 1120, 1117, 1115, 1112, 1110, 1107, 1104, 1101, 1098, 1095, 1092, 1090, 1089, 1088, 1087, 1085, 1083, 1082, 1080, 1079, 1078, 1077, 1074, 1071, 1069, 1067, 1066, 1065, 1064, 1063, 1062, 1059, 1056, 1054, 1051, 1048, 1047, 1044, 1041, 1039, 1038, 1037, 1035, 1033, 1031, 1029, 1027, 1024, 1021, 1019, 1016, 1015, 1013, 1011, 1010, 1008, 1007, 1005, 1002, 1001, 998, 996, 993, 990, 988, 985, 983, 980, 978, 977, 976, 973, 971, 968, 966, 964, 961, 958, 955, 953, 950, 949, 948, 945, 943, 941, 938, 936, 934, 932, 929, 928, 926, 924, 923, 921, 919, 917, 916, 914, 912, 909, 908, 906, 904, 903, 902, 900, 899, 898, 897, 895, 892, 890, 888, 887, 884, 882, 879, 878, 876, 874, 873, 870, 868, 865, 862, 860, 858, 855, 853, 851, 850, 847, 846, 843, 842, 840, 837, 835, 834, 831, 830, 829, 828, 826, 825, 822, 820, 818, 815, 813, 811, 808, 805, 803, 802, 801, 800, 798, 797, 794, 793, 790, 789, 786, 784, 781, 780, 777, 774, 773, 772, 769, 766, 764, 763, 762, 759, 757, 754, 752, 751, 749, 746, 743, 742, 740, 737, 735, 733, 731, 728, 725, 722, 721, 720, 719, 717, 714};
int costos[7][7] = { {0, 9999, 9999, 500, 9999, 9999, 9999}, { 9999, 0, 9999, 9999, 9999, 9999, 480}, { 340, 9999, 0, 9999, 9999, 9999, 9999}, { 9999, 9999, 9999, 0, 9999, 1075,  9999}, { 9999, 900, 9999, 9999, 0, 9999, 9999}, { 9999, 9999, 760, 9999, 9999, 0, 120}, { 9999, 9999, 9999, 9999, 230, 9999, 0} };
int costos2[7][7] = { {0, 9999, 9999, 500, 9999, 9999, 9999}, { 9999, 0, 9999, 9999, 9999, 9999, 480}, { 340, 9999, 0, 9999, 9999, 9999, 9999}, { 9999, 9999, 9999, 0, 9999, 1075,  9999}, { 9999, 900, 9999, 9999, 0, 9999, 9999}, { 9999, 9999, 760, 9999, 9999, 0, 120}, { 9999, 9999, 9999, 9999, 230, 9999, 0} };

// Problema 1
// Escribe aqui la implementaci�n de las funciones del problema 1
int secuenciaLocaIT(int n){

    int a,b,c;
    int suma = 0;

    if(n <= 3){

        return 1;

    } else{
        a = 1;
        b = 1;
        c = 1;

        for(int i = 0; i < 3; i++){
            cout << 1 << " ";
        }

        for(int i = 3; i < n; i++){
            suma = a + b + c;
            cout << suma << " ";
            a = b;
            b = c;
            c = suma;
        }

        return suma;
    }
}

int fibo(int n){

    int a,b;
    int suma = 0;

    if(n <= 2){

        return 1;

    } else{
        a = 1;
        b = 1;

        cout << 0 << " ";

        for(int i = 0; i < 2; i++){
            cout << 1 << " ";
        }

        for(int i = 0; i < n; i++){
            suma = a + b;
            cout << suma << " ";
            a = b;
            b = suma;
        }

        return suma;
    }
}

int serieLocaR(int n)
{
	if(n<=0) {
        return 0;
    }
	else if(n <= 3){
        return 1;
    }
	else {

        return serieLocaR(n-1)+serieLocaR(n-2)+serieLocaR(n-3);
    }
}


// Problema 2
// Escribe aqui la implementaci�n de la funci�n del problema 2
int buscaventas(int arr[], int inicio, int fin){

    int dia;
    int mitad;


    if(inicio > fin){
        return -1;
    } else{

        mitad = (inicio + fin) / 2;

        //cout << mitad << " " << arr[mitad];
        //cout << endl;

        if(arr[mitad + 1] < arr[mitad] && arr[mitad -1] < arr[mitad]){
            return mitad + 1;
        }
        else{

            if(arr[mitad + 1] > arr[mitad]){
                dia = buscaventas(arr, mitad + 1, fin);

            }
            else{

                dia = buscaventas(arr, inicio, mitad - 1);

            }
        }

    }

    return dia;
}


//Problema 3
// Algoritmo de Floyd

int min(int a,int b)
{
 if(a<b)
  return(a);
 return(b);
}

void floyd(int p[7][7],int n)
{
 for(int k=0;k<n;k++)
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}


void floydConexion(int p[7][7],int n)
{
 for(int k=0;k<n;k++)
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}

void printArr7(int arr[7][7], int n){

    int maximo = -1;
    int iX;
    int iY;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
            if(arr[i][j] > maximo && arr[i][j] < 9999){
                maximo = arr[i][j];
                iX = i;
                iY = j;
            }
        }
        cout << endl;
    }

    cout << "MAX " << maximo << endl;
    cout << "i " << iX << endl;
    cout << "j " << iY << endl;


}

void checaVentas(int arr[]){

    int dia = 1;

    for(int i = 0; i < 365; i++){

        if(arr[i] > arr[i+1]){
            cout <<  "dia " << dia << "    " << arr[i+2] << endl;
            break;
        }

        dia++;
    }

}


int main()
{
    //Esscribe aqui las llamadas para probar y responder preguntas del examen
    //secuenciaLocaIT(37);
    //cout << endl;
    //cout << serieLocaR(37);
    //cout << endl;
    //fibo(4);

    //int myArr[] = {2,4,6,8,,5,3,1};

    //cout << buscaventas(ventas, 0, 364) << endl;
    //checaVentas(ventas);

    printArr7(costos,7);
    floyd(costos, 7);
    printArr7(costos,7);
}
