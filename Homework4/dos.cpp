//Sergio Díaz
//A01192313

using namespace std;
#import <iostream> 
#import <vector>



vector<int> vectorData(){
	

}


void printVector(vector<int> v){

for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
   cout << ' ' << *it;
   cout << '\n';

}



void merge(vector<int> arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}


/*


*/

void mergeSort(vector<int> arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}







/*

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






int iCont = 0;
//int arr[500000], c[500000];
vector<int> arr;


void merge(int low, int high, int mid, vector<int> arr)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            //c[k] = arr[i];
            i++;
        }
        else{
            //c[k] = arr[j];
            iCont+= abs(k-j);
            j++;
        }
        k++;
    }
    while (i <= mid){
        //c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high){
        //c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        //arr[i] = c[i];
    }
}
*/






int main(){

	vector<int> arr;

	arr.push_back(5);
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(8);
	arr.push_back(2);

	


}