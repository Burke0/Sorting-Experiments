/*
 * MergeSort.cpp
 */
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const leftSubArray = mid - left + 1;
	auto const rightSubArray = right - mid;

	// Create temp arrays
	auto *leftArray = new int[leftSubArray],
		*rightArray = new int[rightSubArray];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < leftSubArray; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < rightSubArray; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfleftSubArray = 0, // Initial index of first sub-array
		indexOfrightSubArray = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfleftSubArray < leftSubArray && indexOfrightSubArray < rightSubArray) {
		if (leftArray[indexOfleftSubArray] <= rightArray[indexOfrightSubArray]) {
			array[indexOfMergedArray] = leftArray[indexOfleftSubArray];
			indexOfleftSubArray++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfrightSubArray];
			indexOfrightSubArray++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of left[]
	while (indexOfleftSubArray < leftSubArray) {
		array[indexOfMergedArray] = leftArray[indexOfleftSubArray];
		indexOfleftSubArray++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of right[]
	while (indexOfrightSubArray < rightSubArray) {
		array[indexOfMergedArray] = rightArray[indexOfrightSubArray];
		indexOfrightSubArray++;
		indexOfMergedArray++;
	}
}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}







