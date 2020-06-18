#include <iostream>
#include "other_sorting_algorithms.h"
using namespace std;

int sizeOfHeap = 0;
int sizeOfArray = 0;

int getLeftChild(int indexOfParent)
{
   // Get the index of the left child of the  selected by index element
   if ((2 * indexOfParent < sizeOfArray) && (indexOfParent >= 1))
      return indexOfParent * 2;
   return -1;
}

int getRightChild(int indexOfParent)
{
   // Get the index of the right child of the selected by index element
   if (((2 * indexOfParent + 1) < sizeOfArray) && (indexOfParent >= 1))
      return indexOfParent * 2 + 1;
   return -1;
}

int getParent(int arr[], int indexOfChild)
{
   // Get the index of the parent of the current selected element
   // Not used, only for demonstrating purposes
   if ((indexOfChild > 1) && (indexOfChild < sizeOfArray))
      return indexOfChild / 2;
   return -1;
}

void heapify(int arr[], int index)
{
   // Better way of inserting an element into the heap
   int leftChildIndex = getLeftChild(index);
   int rightChildIndex = getRightChild(index);
   int largest = index;

   if ((leftChildIndex <= sizeOfHeap) && (leftChildIndex > 0))
   {
      if (arr[leftChildIndex] > arr[largest])
      {
         largest = leftChildIndex;
      }
   }

   if ((rightChildIndex <= sizeOfHeap && (rightChildIndex > 0)))
   {
      if (arr[rightChildIndex] > arr[largest])
      {
         largest = rightChildIndex;
      }
   }

   if (largest != index)
   {
      swap(&arr[index], &arr[largest]);
      heapify(arr, largest);
   }
}

void heapsort(int a[])
{
   // Orders all elements from min to max
   int temp_sizeOfHeap = sizeOfHeap;
   while (sizeOfHeap > 0)
   {
      swap(&a[1], &a[sizeOfHeap]);
      sizeOfHeap = sizeOfHeap - 1;
      heapify(a, 1);
   }
}

void insertToHeap(int array[], int n)
{
   // This is a more basic way for creating the heap function (instead of the heapify function)
   // but it is much slower, especially for advanced tree structures
   int temp = array[n];
   int i = n;

   while (i > 1 && temp > array[i / 2])
   {
      array[i] = array[i / 2];
      i = i / 2;
   }

   array[i] = temp;
}

void deleteRoot(int arr[])
{
   // Get the last element
   int lastElement = arr[sizeOfHeap];

   // Replace root with first element
   arr[1] = lastElement;

   // Decrease size of heap by 1
   sizeOfHeap = sizeOfHeap - 1;
   sizeOfArray = sizeOfArray - 1;

   // heapify the root node
   heapify(arr, 1);
}

void buildAdvancedMaxHeap(int unsorted_arr[])
{
   // Creates a heap and sorts it from max to min (max-heap)
   // heapify is the most optimal function for creating a heap
   // Time it takes for creation:
   // O(n)
   int i;
   for (i = sizeOfHeap / 2; i >= 1; i--)
      heapify(unsorted_arr, i);
}

void buildBasicMaxHeap(int unsorted_arr[])
{
   // Creates a heap and sorts it from max to min (max-heap)
   // insertToHeap is a more basic funciton, but also it is much slower
   // Time it takes for creation:
   // O(n*log(n))
   for (int i = 1; i < sizeOfHeap; i++)
      insertToHeap(unsorted_arr, i);
}