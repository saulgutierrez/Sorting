#include <iostream>
#include <algorithm>

using namespace std;

// To heapify a subtree rooted with node i
// 12, 11, 13, 5, 6, 7 and n = 6 and i = 2
void heapify(int arr[], int n, int i) {
	int largest = i; // Initialize largest as root // largest = 2
	int l = 2*i + 1; // Left child // l = 2*2 + 1 = 5
	int r = 2*i + 2; // Right child // r = = 2*2 + 2 = 6
	
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest]) { // 5 < 6 (true) && arr[5] = 7 > arr[largest] = arr[2] = 13 => ? (7 > 13) => FALSE
		largest = l; // Won't execute the very first time
	}
	
	// If right child is larger than root
	if (r < n && arr[r] > arr[largest]) { // 6 < 6 (FALSE)
		largest = r; // Won't execute very first time
	}
	
	// If largest is not roor
	if (largest != i) { // i = 2, largest = 2
		swap(arr[i], arr[largest]); // Won't execute the very first time
		// Recursively heapify the sub-tree
		heapify(arr, n, largest);
	}
}

// 12, 11, 13, 5, 6, 7 and size = 6
void heapSort(int arr[], int n) {
	// Build heap
	// Very first time:
	// n = size = 6
	// i = 2
	for (int i = n / 2 - 1; i >= 0; i--) {  // 2 - 0
		heapify(arr, n, i);
	}
	
	// One by one extract an element from heap
	for (int i = n-1; i > 0; i--) {	
		// Move current root to end
		swap(arr[0], arr[i]);
		// Call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	heapSort(arr, n);
	// Insert the sorted array into the same array
	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
