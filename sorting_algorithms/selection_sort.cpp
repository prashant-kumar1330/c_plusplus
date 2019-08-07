//time complexity of selection sort is O(n^2)
#include<iostream>
#include<time.h>
using namespace std;
int main(){
   int x;
   cin>>x;
   int arr[x];
   int steps=0;
   for(int i=0;i<x;i++){
       int temp;
       cin>>temp;
       arr[i]=temp;
   }
 clock_t start=clock();

    for(int j=0;j<x;j++){
      int min=1000000;
      int min_index;
      for(int i=j;i<x;i++){
           
         if(arr[i]<min){
             steps++;
         min = arr[i];
         min_index = i;
         }
      }
          int temp = arr[j];
           arr[j] = min;
          arr[min_index] = temp;
    }
 clock_t end=clock();
    for(int j=0;j<x;j++){
       cout<<arr[j]<<" ";
    }
    cout<<endl;
    cout<<"time rquired "<<end-start<<endl;
    cout<<"steps "<<steps;

}