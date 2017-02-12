#include <iostream>
using namespace std;

const int SIZE = 15;

void mergeSort(int inputArray[], int start, int end);

void merge(int inputArray[], int start, int mid, int end);

void displayArray(int inputArray[]);

int main() {

	int testArray[] = {55, 47, 23, 77, 32, 3, 9, 13, 27, 101, 44, 6, 2, 15, 57};

	displayArray(testArray);
	mergeSort(testArray, 0, SIZE - 1);
	displayArray(testArray);

	cout << endl;
	return 0;
}

void mergeSort(int inputArray[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(inputArray, start, mid);
	mergeSort(inputArray, mid + 1, end);
	merge(inputArray, start, mid, end);
	}

void merge(int inputArray[], int start, int mid, int end) {
	int temp[end - start + 1];
	int left = start;
	int right = mid + 1;

	int k = 0;
	while (left <= mid && right <= end) {
		if (inputArray[left] < inputArray[right]) {
			temp[k++] = inputArray[left++];
		}
		else {
			temp[k++] = inputArray[right++];
		}
	}
	if (left <= mid) {
		while (left <= mid) {
			temp[k++] = inputArray[left++];
		}
	}
	else {
		while (right <= end) {
			temp[k++] = inputArray[right++];
		}
	}
	k = 0;
	for (int i = start; i <= end; i++) {
		inputArray[i] = temp[k++];
	}
}

void displayArray(int inputArray[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << inputArray[i] << " ";
	}
	cout << endl << endl;
}