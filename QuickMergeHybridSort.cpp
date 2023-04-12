/*
 * QuickMergeHybridSort.cpp
 *
 * J. Alex Burke
 * array of size 𝑛 is split into ⌈√𝑛⌉sub-arrays of
 * size √𝑛(except for the last sub-array,
 * which can have less than √𝑛elements)
 * each sub-array is sorted using standard Quick Sort,
 * then the sorted sub-arrays are merged using a linear merge
 */

#include <bits/stdc++.h>
#include "QuickSort.h"
using namespace std;



void sqrtNSplit(int arr[], int low, int high)
{
	// Square root of Array size
	int sqrtVal = sqrt(double(high - low));
	//remainder if array size is not perfect square
	double rem= remainder(sqrt(double(high - low)), sqrtVal);

	//quick sort each partition
	for (int i=0; i<sqrtVal; i++)
		quickSort(arr, i*sqrtVal, (sqrtVal*i+sqrtVal)-1);

	// Quicksort remainder
	if(abs(rem)>0)
		quickSort(arr,sqrtVal*sqrtVal,high);
}

void sqrtMerge(int array[], int low, int high)
{

	int sqrtVal 	= 	sqrt(double(high - low));
	//implement a min heap using priority queue
	priority_queue <int, vector<int>, greater<int> > pq;

	for(int j=0; j<sqrtVal; j++)
		for(int i=0; i< sqrtVal; i++)
				pq.push(array[((sqrtVal*i)+j)]);

	//copy data back into array
	for(int j=0; j<high-low; j++)
	{
		array[j]=pq.top();
		pq.pop();
	}
}


/*
	int finalArray[high-low];
	//start and stop indices for square root subarrays
	int startIndex[sqrtVal+1];
	int stopIndex[sqrtVal+1];
	for( int i=0; i< sqrtVal; i++)
	{
		startIndex[i]=i*sqrtVal;
		stopIndex[i]=(i*sqrtVal+sqrtVal)-1;
	}
	startIndex[sqrtVal+1]=sqrtVal*sqrtVal;
	stopIndex[sqrtVal+1]=high;


	//poor time efficiency O(n^2) linear merge
	for(int j=0; j<high-low; j++)
	{
		int min=INT_MAX;
		int* p;
		for( int i=0; i<=sqrtVal; i++)
		{
			if(startIndex[i]<=stopIndex[i])
				if (array[startIndex[i]]<min)
				{
					min=array[startIndex[i]];
					p=&startIndex[i];
				}
		}
	finalArray[j]=min;
	(*p)++;
	}
}*/



