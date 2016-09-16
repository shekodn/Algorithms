//Sergio Díaz
//A01192313
using namespace std;
#import <iostream> 
#include <array>
#include <vector>
#include <math.h>     

int iComparaciones = 0;

int divide(vector<char> v, int iFirst, int iLast){

	int iIndex;
	char cA = 'a';
	char cB = 'b';

	if (iFirst > iLast) {

		iIndex = -1;
		iComparaciones++;

	} else {

		int iMiddle = (iFirst + iLast) / 2;

		if (v[iMiddle] == cB && v[iMiddle - 1] == cA){

			iIndex = iMiddle;
			iComparaciones++;

		}  else {

			if (v[iMiddle] >= cB) {

				iIndex = divide(v, iFirst, iMiddle);
				iComparaciones++;

			} else {

				iIndex = divide(v, iMiddle + 1, iLast);
				iComparaciones++;
			}
		}
	}

	return iIndex;
}

void secuencias(vector<char> v){

	int iCantidadA = divide(v, 0, v.size());
	int iCantidadB = v.size() - divide(v, 0, v.size());

	if (0 > iCantidadA )	{

		iCantidadB = 0;
		iCantidadA = v.size();

	}

	cout << "     Sequence ->";
	for (vector<char>::iterator it = v.begin() ; it != v.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';

    cout << "         Size -> " << v.size() << endl;
	cout << "Comparaciones -> " << iComparaciones << endl;
	cout << "     # of A's -> " << iCantidadA << endl;
	cout << "     # of B's -> " << iCantidadB << endl;
	cout << endl;

}

int main(int argc, char const *argv[]){

	//Caso 1
	vector<char> a1;

	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('a');
	a1.push_back('b');

	secuencias(a1);

	//Caso 2
	vector<char> a2;

	a2.push_back('a');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	a2.push_back('b');
	iComparaciones = 0;

	secuencias(a2);

	//Caso 3
	vector<char> a3;

	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('a');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	a3.push_back('b');
	
	iComparaciones = 0;

	secuencias(a3);
}