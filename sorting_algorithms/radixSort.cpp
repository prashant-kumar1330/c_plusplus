#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int getmax(int a[], int n)
{
  int max = a[0];
  for (int x=1; x<n; x++)
    if (a[x] > max)
      max = a[x];
  return max;
}


void CountSort(int a[], int n, int exp)
{
  int result[n], i, count[10] = {0};


  for (i =0; i <n; i++)
    count[(a[i] / exp) % 10]++;

  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; i++)
    count[i] += count[i-1];

  // Resultant output array
  for (i =n-1; i>= 0; i--)
  {
    result[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}

// Radix Sort to sort a[] of given size.
void radixsort(int a[], int n)
{
  int exp, i;
  i = getmax(a, n);
  for (exp = 1; i/exp > 0; exp *= 10)
    CountSort(a, n, exp);
}
// Driver Program
int main()
{
  int n;
  cout<<" Enter the number of elements to be sorted: ";
  cin>>n;
    int a[n];

  cout<<"\n Enter the elements: ";

   for(long i=0;i<n;i++){
        a[i]=rand();
    }
     double start = clock();
    radixsort(a, n);
  double time = clock() - start;

  cout<<"\nSorted List: ";
  for (int i = 0; i < n; i++)
   {
    cout<<a[i]<<", ";
   }

  cout<<endl;
    cout<<"time taken "<<time;
  return 0;
}
