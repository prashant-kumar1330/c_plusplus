//time complexity of insertion sort is O(n^2)
#include<iostream>
#include<time.h>
using namespace std;
void insertion_sort(int arr[10],int n){
     int steps=0;
    for(int i=0;i<n-1;i++){
        int curr = arr[i+1];
        int j=i;
        while(arr[j]>curr && j>=0){
            steps++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
    cout<<"steps "<<steps<<endl;
     
}
int main(){
     int x;
   cin>>x;
   int arr[x];
   for(int i=0;i<x;i++){
       int temp;
       cin>>temp;
       arr[i]=temp;
   }   
clock_t start =clock();
    insertion_sort(arr,x);
    clock_t end=clock()-start;
  
      cout<<"time required "<<end;
         cout<<endl;
    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }
   
}