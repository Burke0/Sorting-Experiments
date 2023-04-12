/*
 * AlgorithmsProject1.cpp
 *
 * J. Alex Burke
 */

#include <iomanip>
#include <iostream>
#include <chrono>
#include "QuickSort.h"
#include "MergeSort.h"
#include "QuickMergeHybridSort.h"
using namespace std;

//Utility function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " "<<endl;
}
int main()
{
	 double time_taken;
	 srand(time(0));//rng seed

	for(int i=100000; i<=1000000; i+=100000)
	{
	   int *randArray1=new int[i],*randArray2=new int[i],*randArray3=new int[i],*randArray4=new int[i];

	   //generate numbers between 0 and 99999 to fill 4 duplicate arrays
	   for(int j=0;j<i;j++)
		  randArray1[j]=randArray2[j]=randArray3[j]=randArray4[j]=rand()%100000;
	   cout<<"Array Size: "<<i<<endl;

	   //Quick Sort
	   auto start=chrono::high_resolution_clock::now();
	   quickSort(randArray1, 0, i - 1);
	   auto end=chrono::high_resolution_clock::now();
	   time_taken=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	   time_taken *= 1e-9;
	   cout<<"QS: "<<fixed<<setprecision(2)<<time_taken<<" sec " << endl;

	   //Merge Sort
	   start=chrono::high_resolution_clock::now();
	   mergeSort(randArray2, 0, i - 1);
	   end=chrono::high_resolution_clock::now();
	   time_taken=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	   time_taken *= 1e-9;
	   cout<<"MS: "<<fixed<<setprecision(2)<<time_taken<<" sec " << endl;

	   //Quick/Insertion Sort
	   start=chrono::high_resolution_clock::now();
	   quickSortWithInsertion(randArray3, 0, i - 1);
	   end=chrono::high_resolution_clock::now();
	   time_taken=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	   time_taken *= 1e-9;
	   cout<<"QI: "<<fixed<<setprecision(2)<<time_taken<<" sec " << endl;

	   //Quick/Merge Sort
	   start=chrono::high_resolution_clock::now();
	   sqrtNSplit(randArray4, 0, i - 1);
	   sqrtMerge(randArray4, 0, i - 1);
	   end=chrono::high_resolution_clock::now();
	   time_taken=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	   time_taken *= 1e-9;
	   cout<<"QM: "<<fixed<<setprecision(2)<<time_taken<<" sec " << endl;

	  // printArray(randArray4,i-1);
	   delete [] randArray1;
	   delete [] randArray2;
	   delete [] randArray3;
	   delete [] randArray4;
	}
	return 0;
}

