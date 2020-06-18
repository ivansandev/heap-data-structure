#include <iostream>
using namespace std;

int sizeOfHeap = 0;
int sizeOfArray = 0;

void swap(int *a, int *b)
{
   // Used for swapping elements in the heap (also called sifting the elements up/down)
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int leftChild(int indexOfParent)
{
   // Get the index of the left child of the  selected by index element
   if ((2 * indexOfParent < sizeOfArray) && (indexOfParent >= 1))
      return indexOfParent * 2;
   return -1;
}

int rightChild(int indexOfParent)
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
   // Time it takes for creation:
   // O(n)
   int leftChildIndex = leftChild(index);
   int rightChildIndex = rightChild(index);
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
   // Time it takes for creation:
   // O(n*log(n))
   int temp = array[n];
   int i = n;

   while (i > 1 && temp > array[i / 2])
   {
      array[i] = array[i / 2];
      i = i / 2;
   }

   array[i] = temp;
}

int deleteFromHeap(int arr[], int n)
{
   // delete element and keep it at the end of the array given
   int i, j, x, temp, val;
   val = arr[1];
   x = arr[n];
   arr[1] = arr[n];
   arr[n] = val;
   i = 1;
   j = i * 2;
   while (j < n - 1)
   {
      if (arr[j + 1] > arr[j])
         j = j + 1;
      if (arr[i] < arr[j])
      {
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         i = j;
         j = 2 * j;
      }
      else
         break;
   }
   return val;
}

void buildAdvancedMaxHeap(int unsorted_arr[])
{
   // Creates a heap and sorts it from max to min (max-heap)
   // heapify is the most optimal function for creating a heap
   int i;
   for (i = sizeOfHeap / 2; i >= 1; i--)
      heapify(unsorted_arr, i);
}

void buildBasicMaxHeap(int unsorted_arr[])
{
   // Creates a heap and sorts it from max to min (max-heap)
   // insertToHeap is a more basic funciton, but also it is much slower
   for (int i = 1; i < sizeOfHeap; i++)
      insertToHeap(unsorted_arr, i);
}

int main()
{
   // The tree is going to start from index 1, so index 0 in the array should be ignored
   int arr[] = {0, 1, 5, 2, 3, 10, 9, 19};
   sizeOfArray = sizeof(arr) / sizeof(arr[0]);
   sizeOfHeap = sizeOfArray - 1;

   buildAdvancedMaxHeap(arr);
   for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   heapsort(arr);
   for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}