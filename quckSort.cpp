#include <iostream>
using namespace std;

// QuickSort: Choosing middle element as a pivot element
int quicksort(int array[], int low, int high) {
	if (low >= high)
		return 0;
	
	int mid = (low + high) / 2; // Get index of pivot
	int pivot = array[mid];
	int i = low;
	int j = high;
	int temp;
	
	// Comparing two sides of the list with the pivot
	// and recursively, order each element into two list
	// one smaller than pivot, and another bigger than pivot
	while (i <= j) 
	{
		while (pivot > array[i])
			i++;
			
		while (pivot < array[j])
			j--;
		
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	
	// Calling QuickSort for the first sub list
	if (low < j)
		// Callng recursive function
		quicksort(array, low, j);
	
	// Calling QuickSort for the second sub list
	if (i < high)
		// Calling recursive function
		quicksort(array, i, high);
}

int main() {
	int array[] = {9, 3, 7, 5, 16, 4, 8, 2};
	int n = sizeof(array) / sizeof(array[0]);
	cout << "Array elements before sorting :\n";
	for(int i = 0; i <= n; i++) {
		cout << array[i] << "\t";
	}
	// Call the Quick Sort
	// Pass three parameters:
	// The array element,
	// First index of the array
	// Last index of the array
	quicksort(array, 0, n);
	cout << "\nArray elements after sorting:\n";
	for(int i = 0; i <= n; i++) {
		cout << array[i] << "\t";
		array[i] = '\0';
	}
	return 0;
}
