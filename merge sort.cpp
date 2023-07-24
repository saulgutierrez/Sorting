#include <iostream>
using namespace std;

// Two way Merge Sort
void merge(int arr[], int l, int r, int mid) {
	int i, j, k, c[50];
	i = l;
	k = l;
	j = mid + 1;
	
	// Sorting the sub list inserting the element into final list
	while(i <= mid && j <= r) {
		if(arr[i] < arr[j]) {
			c[k++] = arr[i++];
		} else {
			c[k++] = arr[j++];
		}
	}
	
	// Assigning remaining elements of first sub list
	while (i <= mid) {
		c[k++] = arr[i++];
	}
	
	// Assigning remaining elements of second sub list
	while (j <= r) {
		c[k++] = arr[j++];
	}
	
	// Assingning sorted elements into array
	for(i = l; i < k; i++) {
		arr[i] = c[i];
	}
}

// Merge Sort
void merge_sort(int arr[], int l, int r) {
	int mid;
	if(l < r) {
		// Find middle to divide array into two halves
		mid = (l + r) / 2;
		// Calling merge sort for first half
		merge_sort(arr, l, mid);
		// Calling merge sort for second half
		merge_sort(arr, mid+1, r);
		// Merge two sorted arrays
		merge(arr,l,r,mid);
	}
}

// Main function
int main() {
	int array[] = {2,5,3,23,8,1};
	int n;
	n = sizeof(array)/sizeof(array[0]);
	
	cout << "Array elements before sorting: \n";
	for(int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	if (n == 0) {
		cout << "\nThere is nothing to sort";
		return 0;
	} else if (n == 1) {
		cout << "\nSingle element is already sorted";
	} else {
		merge_sort(array, 0, n);
		cout << "\nArray elements after sorting: \n";
		for(int i = 0; i < n; i++) {
			cout << array[i] << "\t";
		}
	}
	cin.get();
}
