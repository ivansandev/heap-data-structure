#include <iostream>
using namespace std;

int sizeOfHeap = 0;
int sizeOfTree = 0;

void swap(int *a, int *b)
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}

int leftChild(int arr[], int indexOfParent)
{
   // Get the index of the left child of the current selected element (by index, not value)
   if ((2 * indexOfParent < sizeOfTree) && (indexOfParent >= 1))
      return indexOfParent * 2 - 1;
   return -1;
}

int rightChild(int arr[], int indexOfParent)
{
   // Get the index of the right child of the current selected element  (by index, not value)
   if (((2 * indexOfParent + 1) < sizeOfTree) && (indexOfParent >= 1))
      return indexOfParent * 2 - 1;
   return -1;
}

int getParent(int arr[], int indexOfChild)
{
   // Get the index of the parent of the current selected element
   if ((indexOfChild > 1) && (indexOfChild < sizeOfTree))
      return indexOfChild / 2;
   return -1;
}

void heapify(int arr[], int index)
{
   // Better way of inserting an element into the heap
   // Time it takes for creation:
   // O(n)
   int leftChildIndex = leftChild(arr, index);
   int rightChildIndex = rightChild(arr, index);
   int largest = index;

   if ((leftChildIndex <= sizeOfHeap) && (leftChildIndex > 0))
   {
      if (arr[leftChildIndex] > arr[largest])
      {
         largest = leftChildIndex;
      }
   }

   if ((rightChildIndex <= sizeOfTree && (rightChildIndex > 0)))
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
   while (sizeOfHeap > 0)
   {
      swap(&a[1], &a[sizeOfHeap]);
      sizeOfHeap = sizeOfHeap - 1;
      heapify(a, 1);
   }
}

void insertToHeap(int array[], int n)
{
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

void createMaxHeap(int unsorted_arr[])
{
   // Creates a heap and sorts it from min to max (max-heap)
   for (int i = 1; i < sizeOfHeap; i++)
      // Slower but more simple function for creating the heap
      // insertToHeap(unsorted_arr, i);
      heapify(unsorted_arr, i);
}

int main()
{
   int arr[] = {0, 1, 5, 2, 3, 10, 9, 19};
   sizeOfTree = sizeof(arr) / sizeof(arr[0]);
   sizeOfHeap = sizeOfTree - 1;
   createMaxHeap(arr);
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