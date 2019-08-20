#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int partition(int * a,int s,int e)
{
  int i=s-1;
  int j=s;
  int pivot=a[e];
  for(;j<e;j++)
  {
    if(a[j]<=pivot)
    {
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[i+1],a[e]);
  return i+1;
}
void quicksort(int *arr,int start,int end)
{
  if(start>=end)
  {
    return;
  }
  int p=partition(arr,start,end);
  quicksort(arr,start,p-1);
  quicksort(arr,p+1,end);
  return;
}
int main(){
int n;
    cout<<"Enter the size ";
    cin>>n;
    int arr[n];
    for(long i=0;i<n;i++){
        arr[i]=rand();
    }
    clock_t t =clock();
    quicksort(arr,0,n-1);
    double e= clock()-t;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"time taken= "<<e;


return 0;
}
