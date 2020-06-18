#include <iostream>
#include "heap.h"
using namespace std;

void createRandomArray(int arr[])
{
   for (int i = 1; i < 10001; i++)
   {
      arr[i] = rand() % 1000000;
   }
}

int main ()
{
   cout << endl
        << "Performance testing heap creation and heapsort \n(on random 10 000 numbers)" << endl;
   int random_arr[10001], start, end;
   createRandomArray(random_arr);
   sizeOfArray = sizeof(random_arr) / sizeof(random_arr[0]);
   sizeOfHeap = sizeOfArray - 1;
   start = clock();
   buildAdvancedMaxHeap(random_arr);
   end = clock();
   cout << "Heap creation time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
   start = clock();
   heapsort(random_arr);
   end = clock();
   cout << "Heapsort time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

   cout << endl
        << "Performance testing other sorting algorithms \n(on random 10 000 numbers)" << endl;
   createRandomArray(random_arr);
   sizeOfArray = sizeof(random_arr) / sizeof(random_arr[0]);
   start = clock();
   quickSort(random_arr, 1, sizeOfArray - 1);
   end = clock();
   cout << "Quicksort time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

   createRandomArray(random_arr);
   sizeOfArray = sizeof(random_arr) / sizeof(random_arr[0]);
   start = clock();
   selectionSort(random_arr, sizeOfArray);
   end = clock();
   cout << "SelectionSort time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

   createRandomArray(random_arr);
   sizeOfArray = sizeof(random_arr) / sizeof(random_arr[0]);
   start = clock();
   bubbleSort(random_arr, sizeOfArray);
   end = clock();
   cout << "BubbleSort time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

   createRandomArray(random_arr);
   sizeOfArray = sizeof(random_arr) / sizeof(random_arr[0]);
   start = clock();
   mergeSort(random_arr, 1, sizeOfArray - 1);
   end = clock();
   cout << "MergeSort time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
}
