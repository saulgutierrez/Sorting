#include <iostream>
using namespace std;

int main()
{
	int arrSize;
	int aux;
	cout << "Enter the size of the array: ";
	cin >> arrSize;

	// Dynamic array
	int* arr = new int[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Type value " << i << ": ";
		cin >> arr[i];
	}

	cout << "Show original list: " << endl;

	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " - ";
	}

	cout << endl << "Bubble sorting... ";

	// Two pointers
	for (int i = 0; i < arrSize - 1; i++) {
		for (int j = i + 1; j < arrSize; j++) {
			// Swapping
			if (arr[i] > arr[j]) {
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}

	cout << endl << "Output: " << endl;

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " - ";
	}
}