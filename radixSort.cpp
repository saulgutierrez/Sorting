#include <iostream>

using namespace std;

// Get maximum value in array[]
int getMax(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

// Counting sort of arr[] according to the digit
void countSort(int array[], int n, int exp) {
	int output[n], i, count[10] = {0};
	
	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;
	
	// Modifying count
	for(i = 1; i < 10; i++)
		count[i] += count[i - 1];
	
	// Build the output array
	for(i = n-1; i >= 0; i--) {
		output[count[ (array[i]/exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10 ]--;
	}
	
	// Copy the output to array
	for (int i = 0; i < n; i++)
		array[i] = output[i];
}

void radixsort(int array[], int n) {
	// Find the maximun number to know number of digits
	int m = getMax(array, n);
	
	// Do counting sort for every digit
	for(int exp = 1; m/exp > 0; exp *= 10)
		countSort(array, n, exp);
}

int main() {
	int array[] = {14, 340, 532, 24, 967, 535, 106};
	int n = sizeof(array)/sizeof(array[0]);
	radixsort(array, n);
	cout << "Sorted elements are: \n";
	for(int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	return 0;
}
