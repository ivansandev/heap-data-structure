#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
   // Used for swapping elements in the heap (also called sifting the elements up/down)
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int partition(int arr[], int low, int high)
{
   int pivot = arr[high]; // pivot
   int i = (low - 1);     // Index of smaller element

   for (int j = low; j <= high - 1; j++)
   {
      if (arr[j] <= pivot)
      {
         i++;
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
      int pi = partition(arr, low, high);

      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
}

void selectionSort(int array[], int size)
{
   for (int step = 1; step < size - 1; step++)
   {
      int min_idx = step;
      for (int i = step + 1; i < size; i++)
      {

         if (array[i] > array[min_idx])
            min_idx = i;
      }

      // put min at the correct position
      swap(&array[min_idx], &array[step]);
   }
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n - 1; i++)
   {
      swapped = false;
      for (j = 0; j < n - i - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            swap(&arr[j], &arr[j + 1]);
            swapped = true;
         }
      }
      if (swapped == false)
         break;
   }
}

void merge(int arr[], int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   /* create temp arrays */
   int L[n1], R[n2];

   /* Copy data to temp arrays L[] and R[] */
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];

   /* Merge the temp arrays back into arr[l..r]*/
   i = 0; // Initial index of first subarray
   j = 0; // Initial index of second subarray
   k = l; // Initial index of merged subarray
   while (i < n1 && j < n2)
   {
      if (L[i] <= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   /* Copy the remaining elements of L[], if there 
       are any */
   while (i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }

   /* Copy the remaining elements of R[], if there 
       are any */
   while (j < n2)
   {
      arr[k] = R[j];
      j++;
      k++;
   }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
   if (l < r)
   {
      // Same as (l+r)/2, but avoids overflow for
      // large l and h
      int m = l + (r - l) / 2;

      // Sort first and second halves
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      merge(arr, l, m, r);
   }
}