#include <iostream>
using namespace std;

// Insertion function
void insertionSort(int array[], int n) {
// ind 0  1  2  3  4   5
	// 6, 8, 1, 4, 10, 9 // 6 ... 8 4 10 9 // ... 6 8 4 10 9
	int temp, i, location;
	
	// Inserting element at required location
	for (i = 0; i < n; i++) { // i = 2
		temp = array[i]; // temp = 6 // temp = 8 // temp = 1
		location = i - 1; // loc = -1 // loc = 0 // loc = 1
		while(location >= 0 && array[location] > temp) { // 8 > 1 // 6 > 1
			array[location + 1] = array[location]; // array[2] = 8 // array[1] = 6
			location = location - 1; // loc = 0 // loc = -1
		}
		array[location + 1] = temp; // array[0] = 1
	}
	cout << "Sorted array elements are: \n";
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
}

int main() {
	int array[] = { 6, 8, 1, 4, 10, 9 };
	int n = sizeof(array) / sizeof(array[0]);
	cout << "Array elements before sorting: \n";
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	// Calling Insert Sort function
	insertionSort(array, n);
	return 0;
}
