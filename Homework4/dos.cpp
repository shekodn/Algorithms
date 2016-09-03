//Sergio Díaz
//A01192313

using namespace std;
#import <iostream> 
#import <vector>



vector<int> vectorData(){

	vector<int> v;

	v.push_back(5);
	v.push_back(3);
	v.push_back(7);
	v.push_back(9);
	v.push_back(1);
	v.push_back(4);
	v.push_back(8);
	v.push_back(2);

	return v;
}

void quickSort(vector<int> v){


}

void merge(vector<int> arr, int size1, int size2){

	int temp[size1+size2];
    int ptr1 = 0;
    int ptr2 =0;

    while (ptr1+ptr2 < size1+size2) {
        if (ptr1 < size1 && arr[ptr1] <= arr[size1+ptr2] || ptr1 < size1 && ptr2 >= size2)
            temp[ptr1+ptr2] = arr[ptr1++];

        if (ptr2 < size2 && arr[size1+ptr2] < arr[ptr1] || ptr2 < size2 && ptr1 >= size1)
            temp[ptr1+ptr2] = arr[size1+ptr2++];
    }

    for (int i=0; i < size1+size2; i++)
        arr[i] = temp[i];
}


void mergeSort(vector<int> v, int iFirst, int iLast){

	if (iFirst < iLast) {

		int iMiddle = (iFirst + iLast) / 2;
		mergeSort(v, iFirst, iMiddle);
		mergeSort(v, iMiddle + 1, iLast);
		merge(v, iFirst, iLast);		
	}

}



int main(){

	//quickSort(vector());
	mergeSort(vectorData(), vectorData().begin(), vectorData().end());

}