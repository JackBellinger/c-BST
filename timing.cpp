#include "BST.h"
#include "Heap.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <cstddef>
#include <cmath>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

void generateForwardSorted(int* array, double length)
{

	for(int i = 0; i < length; i++)
	{
		array[i] = i;
	}
}

void generateBackwardSorted(int* array, double length)
{

	for(int i = 0; i < length; i++)
	{
		array[i] = length - 1 - i;
	}
}
void generateRandomSorted(int* array, double length)
{
	generateForwardSorted(array, length);
	Heap<int> heap(length);
	heap.heapSortRandomizer(array, length);
}
void printArray(double* array, double length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void printArray(int* array, double length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
bool validateAscendingSort(int* array, double length)
{//checks if every element is greater than the previous
	for(int i = 1; i < length; i++)
		if(array[i - 1] > array[i])
		{	
			cout << array[i-1] << " > " << array[i] << endl;
			return false;
		}
	return true;
}
double timeBasicSorts(size_t (*sortingAlgo)(int*, double), int* array, double length)
{
	// The "auto" type determines the correct type at compile-time
	auto startT = std::chrono::system_clock::now();

	size_t swaps = sortingAlgo(array, length);

	auto endT = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
	std::time_t end_time = std::chrono::system_clock::to_time_t(endT);

	//cout << "finished at " << std::ctime(&end_time) 
	//     << "elapsed time: " << time << " s"
	//     << "\nNumber of swaps: " << swaps << "\n";
	//double checks that the array is sorted correctly
	if(validateAscendingSort(array, length))
		cout << "Array is Sorted Correctly" << endl;
	else
		cout << "Array is not Sorted Correctly" << endl;
	return time;
}

double timeRecursiveSorts( size_t (*sort) (int*, size_t, size_t), int* array, size_t start, size_t end)
{
	// The "auto" type determines the correct type at compile-time
	auto startT = std::chrono::system_clock::now();

	size_t swaps = sort(array, start, end);

	auto endT = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
	std::time_t end_time = std::chrono::system_clock::to_time_t(endT);

	/*cout << "finished at " << std::ctime(&end_time) 
	  << "elapsed time: " << time << " s"
	  << "\nNumber of swaps: " << swaps << "\n";
	//double checks that the array is sorted correctly
	if(validateAscendingSort(array, end))
	cout << "Array is Sorted Correctly" << endl;
	else
	cout << "Array is not Sorted Correctly" << endl;
	 */
	return time;
}
double timeHeapSort(int* array, int size)
{
	Heap<int> heap(size);
	auto startT = std::chrono::system_clock::now();

	heap.heapSort(array, size);

	auto endT = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
	std::time_t end_time = std::chrono::system_clock::to_time_t(endT);

	return time;
}
enum bstOperation
{
	insert = 0,
	find = 1,
	delet = 2
};
double timeBST(BST<int>* tree, int op, int value)
{
	auto startT = std::chrono::system_clock::now();
	switch(op)
	{
		case 0://::insert:
			tree->bstInsert(value);
			break;
		case 1://::find:
			tree->bstSearch(value);
			break;
		case 2://::delet:
			tree->bstDelete(value);
	}
	auto endT = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
	std::time_t end_time = std::chrono::system_clock::to_time_t(endT);

}
int lab7()
{

	string opNames[3] = {"Insertion", "Searching", "Deletion"};

	static double opTimes[4][10];
	int numSizes = 0;
	int numSamples = 10;
	for(int SIZE = 1000; SIZE <= 10000; SIZE += 1000)
	{
		
		opTimes[3][numSizes] = SIZE;
		for(int x = 0; x < numSamples; x++)
		{
			BST<int>* tree = new BST<int>();
			int elements[SIZE];
			generateRandomSorted(elements, SIZE);
			for(int op = 0; op < 3; op++)
				for(int i = 0; i < SIZE; i++)
				{
					double time = timeBST(tree, op, elements[i]);
					opTimes[op][numSizes] += time;
				}
			tree->cleanNodes();
			delete tree;
		}//samples loop

		for(int op = 0; op < 3; op++)
		{
			opTimes[op][numSizes] = opTimes[op][numSizes] / numSamples;
			//cout << "Average time to 
		}
		numSizes++;
	}//size loop
	double c1 = 0.00001;
	double nlogn[10];
	double c2 = 0.00000012;
	double n2[10];
	for(int i = 0; i < 10; i++)
	{
		nlogn[i] = c1 * opTimes[3][i] * log(opTimes[3][i]);
		n2[i] = c2 * Pow(optimes[3][i], 2);
	}
	cout << "sizes: "; printArray(opTimes[3], 10);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < numSizes; j++)
		{
			
		}
		cout << opNames[i] << ":";
		printArray(opTimes[i], 10);
	}
	
	plt::figure_size(1200, 780);
	plt::plot("nlog(n)", opTimes[3], nlogn);
	plt::plot("n^2", opTimes[3], n2);
	
	for(int i = 0; i < 3; i++)
		plt::plot(opNames[i], opTimes[i]);

	plt::xlim(0, 10000);
	plt::title("BST Operations Timing");
	plt::legend();
	plt::save("./plot.png");
	return 1;
}
int main()
{
	lab7();
}

