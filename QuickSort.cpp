/*
 * QuickSort.cpp
 *
 */


#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes the smaller of the first and last element as pivot,
 * places the pivot element at its correct position in sorted array,
 *  smaller element go to the left of pivot
 *  and greater elements to the right
 */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	if(arr[low]<arr[high])
		pivot=arr[low];
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partIndex = partition(arr, low, high);

		//sort elements before and after partition
		quickSort(arr, low, partIndex - 1);
		quickSort(arr, partIndex + 1, high);
	}
}
void quickSortWithInsertion(int arr[], int low, int high)
{
	int size=high-low-1;
	if(size<=10)//insertion sort
	{
		for( int i=low; i<=high; i++)
		{
			int key=arr[i];
			int j=i-1;

			while(j>=0 && arr[j]>key)
			{
				arr[j+1]=arr[j];
				j=j-1;
			}
			arr[j+1]=key;
		}
	}
	else if (low < high)
	{
		int partIndex = partition(arr, low, high);

		//sort elements before and after partition
		quickSortWithInsertion(arr, low, partIndex - 1);
		quickSortWithInsertion(arr, partIndex + 1, high);
	}
}





