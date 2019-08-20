#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void merge(int arr[100],int start,int mid,int end){
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    int temp[100000];
    int k = 0;
    while(start1<=end1 && start2<=end2){
        if(arr[start1]<arr[start2]){
            temp[k++] = arr[start1++];
        }else{
            temp[k++] = arr[start2++];
       }
    }
    while(start1<=end1){
        temp[k++] = arr[start1++];
    }
    while(start2<=end2){
        temp[k++] = arr[start2++];
    }
    for(int i=0;i<k;i++){
        arr[start++] = temp[i];
    }
}
void merge_sort(int arr[100],int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
    return;
}
int main(){
    int data;

    cout<<"enter no. of values ";
    cin>>data;
    int arr[data];
    for(long i=0;i<data;i++){
        arr[i]=rand();
    }
clock_t t =clock();
merge_sort(arr,0,data-1);
 double e = clock()-t;

for(int i=0;i<data;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"time taken= "<<e;
}
