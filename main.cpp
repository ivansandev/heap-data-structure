#include <iostream>
#include <string>
#include <time.h>
#include "heap.h"
using namespace std;

void printArray(int arr[], string message)
{
   cout << endl;
   cout << message << endl;
   for (int i = 1; i < sizeOfArray; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main()
{
   // The tree is going to start from index 1, so index 0 in the array should be ignored
   int arr[] = {0, 1, 5, 2, 3, 10, 9, 19, 24, 30, 26, 11, 20, 50};
   sizeOfArray = sizeof(arr) / sizeof(arr[0]);
   sizeOfHeap = sizeOfArray - 1;

   buildAdvancedMaxHeap(arr);
   printArray(arr, "Printing the max-heap:");

   deleteRoot(arr);
   printArray(arr, "Printing the max-heap after root deletion:");

   heapsort(arr);
   printArray(arr, "Printing the sorted array (from min to max):");

   return 0;
}