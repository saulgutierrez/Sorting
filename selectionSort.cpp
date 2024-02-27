#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(int array[], int n) {
	int i, min, temp;
	// 6, 8, 1, 4, 10, 9
	for (i = 0; i < n-1; i++) {
		// 1	8	6	4	10	9
		min = i; // min = 0
		for (int j = i+1; j < n; j++) { // j = index[1], j = index[2]
			if (array[j] < array[min]) { // 1 < 6
				min = j; // min = index[2]
			}
		}
		// Code to swap the values // array[0] and array[2]
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	
	// Displaring sorted Elements
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
}

int main() {
	int array[6] = {6, 8, 1, 4, 10, 9};
	int n;
	n = sizeof(array)/sizeof(array[0]);
	cout << "Array before sorting: \n";
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	cout << endl << endl;
	cout << "Array elements after sorting: \n";
	
	// Calling selection Sort
	selectionSort(array, n);
	return 0;
}
