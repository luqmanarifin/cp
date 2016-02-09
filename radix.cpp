// C++ implementation of Radix Sort
#include<iostream>
using namespace std;
 
int bit = 8;
int mask = (1 << bit) - 1;
 
// A utility function to get maximum value in arr[]
 long long getMax( long long arr[], int n)
{
     long long mx = arr[0];
    for ( long long i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort( long long arr[], int n, int shift)
{
     long long output[n]; // output array
    int i, count[1 << bit];
    for(i = 0; i <= mask; i++) {
      count[i] = 0;
    }
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]>>shift)&mask ]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i <= mask; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]>>shift)&mask ] - 1] = arr[i];
        count[ (arr[i]>>shift)&mask ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort( long long arr[], int n)
{
    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    for (int shift = 0; shift < 64; shift += bit)
        countSort(arr, n, shift);
}
 
// A utility function to print an array
void print( long long arr[],  long long n)
{
    for ( long long i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver program to test above functions
int main()
{
     long long arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}