/*myFile2.cpp : Ex2 a2 CSI2372A*/

#include "myFile2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size)
{
	//YOUR CODE HERE
	for(int i = 0; i< size; i++){
		//min value index
		int min = i;
		//iterate through array to find min index
		for(int j= i + 1; j<size; j++){
			if(a[j] < a[min]){
				min = j;

			}
		}
		//swap min index and first 
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;





	}
}