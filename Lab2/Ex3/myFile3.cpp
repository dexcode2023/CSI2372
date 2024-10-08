/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	//YOUR CODE
	int** result = new int*[n];
	int* last;
	for(int i = 0; i < n; i++){
		result[i] = new int[i+1];
		if(i == 0){
			result[i][0] = 1;
			last = result[i];
		} else{
			for(int j = 0; j < i+1; j++){
				if(j==0){
					result[i][0] = 1;
				} else if(j==i){
					result[i][j] =1;
				} else{
					result[i][j] = last[j-1]+last[j];
				}
				

			}
			last = result[i];

		}



	}
	return result;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}