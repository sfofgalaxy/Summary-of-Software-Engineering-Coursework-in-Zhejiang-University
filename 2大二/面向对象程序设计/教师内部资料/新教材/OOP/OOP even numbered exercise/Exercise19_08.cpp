#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template<typename T>
class Heap {
public:
  Heap();
  Heap(T elements[], int arraySize);
  T remove() throw (runtime_error);
  void add(T element);
  int getSize();

private:
  vector<T> v;
};

template <typename T>
Heap<T>::Heap(){
}

template <typename T>
Heap<T>::Heap(T elements[], int arraySize)
{
  for (int i = 0; i < arraySize; i++) {
    add(elements[i]);
  }
}

/* Remove the root from the heap */
template <typename T>
T Heap<T>::remove() throw (runtime_error)
{
  if (v.size() == 0)
    throw runtime_error("Heap is empty");

  T removedElement = v[0];
  v[0] = v[v.size() - 1]; // Move the last to root
  v.pop_back(); // Remove root

  // Maintain the heap property
  unsigned currentIndex = 0;
  while (currentIndex < v.size())
  {
    unsigned leftChildIndex = 2 * currentIndex + 1;
    unsigned rightChildIndex = 2 * currentIndex + 2;

    // Find the maximum between two children
    if (leftChildIndex >= v.size()) break; // The tree is a heap
    int maxIndex = leftChildIndex;
    if (rightChildIndex < v.size())
    {
      if (v[maxIndex] < v[rightChildIndex])
      {
        maxIndex = rightChildIndex;
      }
    }

    // Swap if the current node is less than the maximum
    if (v[currentIndex] < v[maxIndex])
    {
      T temp = v[maxIndex];
      v[maxIndex] = v[currentIndex];
      v[currentIndex] = temp;
      currentIndex = maxIndex;
    }
    else
      break; // The tree is a heap
  }

  return removedElement;
}

/* Insert element into the heap and maintain the heap property */
template <typename T>
void Heap<T>::add(T element)
{
  v.push_back(element); // Append element to the heap
  int currentIndex = v.size() - 1; // The index of the last node

  // Maintain the heap property
  while (currentIndex > 0)
  {
    int parentIndex = (currentIndex - 1) / 2;
    // Swap if the current object is greater than its parent
    if (v[currentIndex] > v[parentIndex] > 0)
    {
      T temp = v[currentIndex];
      v[currentIndex] = v[parentIndex];
      v[parentIndex] = temp;
    }
    else
      break; // the tree is a heap now

    currentIndex = parentIndex;
  }
}

/* Get the number of element in the heap */
template <typename T>
int Heap<T>::getSize()
{
  return v.size();
}

#endif

template <typename T>
void heapSort(T list[], int arraySize);
void bubbleSort(int list[], int length);
void insertionSort(int list[], int length);
void selectionSort(int list[], int length);
void mergeSort(int list[], int length);
int *merge(int list1[], int list2[]);
void quickSort(int list[], int length);
void quickSort(int list[], int first, int last);
int partition(int list[], int first, int last);
int getKey(int number, int position);
void copyList(int list1[], int list[], int length);
void radixSort(int list[], int numberOfDigits, int length);

int main() {

cout << setw(20) << "Array Size" << setw(20) << "Selection Sort" << setw(20) << "Insertion Sort" 
	<< setw(20) <<  "Bubble Sort" << setw(20)  << "Merge Sort" 
	<< setw(20) << "Quick Sort" << setw(20) << "Heap Sort"<< setw(20) 
	<< "Radix Sort" << endl;

int *list;
int *list1;
int *list2;
long startTime;
long endTime;
long executionTime[6][7];

const int BASE = 10000;

for (int k = 0; k < 6; k++) {
	list = new int[k * BASE + BASE];
	list1 = new int[k * BASE + BASE];
	list2 = new int[k * BASE + BASE];

	for (int i = 0; i < (k * BASE + BASE); i++) {
		srand(time(NULL));
		list[i] = (int)(rand() % 100000 + 1);
		list1[i] = list[i];
		list2[i] = list[i];
}

	int length = k * BASE + BASE;

	startTime = time(0);
	selectionSort(list, length);
	endTime = time(0);
	executionTime[k][0] = endTime - startTime;
	
	
	startTime = time(0);
	copyList(list1, list, length);
	insertionSort(list, length);
	endTime = time(0);
	executionTime[k][1] = endTime - startTime;
	
	
	startTime = time(0);
	copyList(list1, list, length);
	bubbleSort(list, length);
	endTime = time(0);
	executionTime[k][2] = endTime - startTime;
	
	
	startTime = time(0);
	copyList(list1, list, length);
	mergeSort(list, length);
	endTime = time(0);
	executionTime[k][3] = endTime - startTime;
	
	
	startTime = time(0);
	copyList(list1, list, length);
	quickSort(list, length);
	endTime = time(0);
	executionTime[k][4] = endTime - startTime;
	
	
	startTime = time(0);
	heapSort(list2, length);
	endTime = time(0);
	executionTime[k][5] = endTime - startTime;
	
	
	startTime = time(0);
	copyList(list1, list, length);
	radixSort(list, 5, length);
	endTime = time(0);
	executionTime[k][6] = endTime - startTime;
}

	for (int i = 0; i < 6; i++) {
		cout << setw(20) << BASE + i * BASE;

		for (int j = 0; j < 7; j++)
			cout << setw(20) << executionTime[i][j];
			cout << endl;
	}
}

/** The method for sorting the numbers */
void selectionSort(int list[], int length) {

	for (int i = length; i >= 1; i--) {

	// Find the maximum in the list[0..i]
	int currentMax = list[0];
	int currentMaxIndex = 0;

	for (int j = 1; j <= i; j++) {
		if (currentMax < list[j]) {
			currentMax = list[j];
			currentMaxIndex = j;
		}
	}

	// Swap list[i] with list[currentMaxIndex] if necessary;
	if (currentMaxIndex != i) {
		list[currentMaxIndex] = list[i];
		list[i] = currentMax;
	}
}
}



/** The method for sorting the numbers */
void insertionSort(int list[], int length) {

	for (int i = 1; i < length; i++) {
		/** insert list[i] into a sorted sublist list[0..i-1] so that
		list[0..i] is sorted. */
		int currentElement = list[i];
		int k;
		for (k = i - 1; k >= 0 && list[k] > currentElement; k--) {
			list[k + 1] = list[k];
		}

		// Insert the current element into list[k+1]
		list[k + 1] = currentElement;
	}
}

/** The method for sorting the numbers */
void bubbleSort(int list[], int length) {
	bool needNextPass = true;
	for (int k = 1; k < length && needNextPass; k++) {
		
		// Array may be sorted and next pass not needed
		needNextPass = false;
		for (int i = 0; i < length - k; i++) {
			if (list[i] > list[i + 1]) {
				// Swap list[i] with list[i + 1]
				int temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				needNextPass = true; // Next pass still needed
			}
		}
	}
}

/** The method for sorting the numbers */
void mergeSort(int list[], int length) {
	if (sizeof(list)/sizeof(int) > 1) {

		// Merge sort the first half
		int *firstHalf = new int[(length)/ 2];
		for (int i = 0; i < (length)/ 2; i++) {
			firstHalf[i] = list[i];
		}
		mergeSort(firstHalf, length/2);
	
		// Merge sort the second half
		int secondHalfLength = (length) - (length/2);
		int *secondHalf = new int[secondHalfLength];
		for (int i = 0; i < secondHalfLength; i++) {
			secondHalf[i] = list[length/2 + i];
		}
		mergeSort(secondHalf, secondHalfLength);
	
		// Merge firstHalf with secondHalf
		int *temp = merge(firstHalf, secondHalf);
		for (int i  = 0; i < length; i++) {
			list[i] = temp[i];
		}
	}
}

int *merge(int list1[], int list2[]) {
	int *temp = new int[sizeof(list1)/sizeof(int) + sizeof(list2)/sizeof(int)];
	unsigned current1 = 0; // Index in list1
	unsigned current2 = 0; // Index in list2
	unsigned current3 = 0; // Index in temp
	
	while (current1 < sizeof(list1)/sizeof(int) && sizeof(list2)/sizeof(int)) {
		if (list1[current1] < list2[current2]) {
			temp[current3++] = list1[current1++];
		} else {
			temp[current3++] = list2[current2++];
		}
	}

	while (current1 < sizeof(list1)/sizeof(int)) {
		temp[current3++] = list1[current1++];
	}

	while (current2 < sizeof(list2)/sizeof(int)) {
		temp[current3++] = list2[current2++];
	}

return temp;
}

void quickSort(int list[], int length) {
	int last = (length - 1);
	quickSort(list, 0, last);
}

void quickSort(int list[], int first, int last) {
	if (last > first) {
		int pivotIndex = partition(list, first, last);
		quickSort(list, first, pivotIndex - 1);
		quickSort(list, pivotIndex + 1, last);
	}
}

/** Partition the array list[first..last] */
int partition(int list[], int first, int last) {
	int pivot = list[first]; // Choose the first element as the pivot
	int low = first + 1; // Index for forward search
	int high = last; // Index for backward search
	
	while (high > low) {
		// Search forward from left
		while (low <= high && list[low] <= pivot) {
			low++;
		}
		
		// Search backward from right
		while (low <= high && list[high] > pivot) {
			high--;
		}

		// Swap two elements in the list
		if (high > low) {
			int temp = list[high];
			list[high] = list[low];
			list[low] = temp;
		}
	}

	while (high > first && list[high] >= pivot) {
		high--;
	}

	// Swap pivot with list[high]
	if (pivot > list[high]) {
		list[first] = list[high];
		list[high] = pivot;
		return high;
	} else {
		return first;
	}
}


template <typename T>
void heapSort(T list[], int arraySize)
{
  Heap<T> heap;

  for (int i = 0; i < arraySize; i++)
    heap.add(list[i]);

  for (int i = 0; i < arraySize; i++)
    list[i] = heap.remove();
}

/** Sort the int array list. numberOfDigits is the number of digits
* in the largest number in the array */
void radixSort(int list[], int numberOfDigits, int length) {
	vector<int> *buckets = new vector<int>[10];
		for (int i = 0; i < 10; i++) {
			vector<int> vec;
			buckets[i] = vec;
		}

		for (int position = 0; position <= numberOfDigits; position++) {
			// Clear buckets
			for (int i = 0; i < 10; i++) {
				buckets[i].clear();
			}     

			// Distribute the elements from list to buckets
			for (int i = 0; i < length; i++) {
				int key = getKey(list[i], position);
				buckets[key].push_back(list[i]);
			}

			// Now move the elements from the buckets back to list
			int k = 0; // k is an index for list
			for (int i = 0; i < 10; i++) {
				//if (buckets[i] != NULL) {
					for (unsigned j = 0; j < buckets[i].size(); j++)
					list[k++] = buckets[i][j];
				//}
			}
		}
}

/** Return the digit at the specified position.
* The last digit's position is 0. */
int getKey(int number, int position) {
	int result = 1;
	for (int i = 0; i < position; i++) result *= 10;
	
	return (number / result) % 10;
}

void copyList(int list1[], int list[], int length) {
	for (int i = 0; i < length; i++)
		list[i] = list1[i];

}
