//Sergio Díaz
//A01192313

using namespace std;
#import <iostream> 
   
int iContador = 0;


int power(int iA, int iB){

	int iX;

    if (iB == 0){
    	iContador++;
        return(1);
    }

    iX = power(iA,iB/2);

    if (iB % 2 != 0){
    	iContador++;
    	return(iA*iX*iX);
    }
    else {

        return(iX * iX);
    }
}


int main(int argc, char const *argv[]){

	int iA, iB;

	cout << "Ingrese A -> ";
	cin >> iA;
	cout << "Ingrese B -> "; 
	cin >> iB;


	cout << "a ^ b: " << power(iA, iB) << endl;
	cout << "Contador: " << iContador << endl;


}
