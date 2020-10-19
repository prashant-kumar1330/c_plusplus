#include<iostream>
#include<stdio.h>
using namespace std;

bool isSafe(int arr[100][100],int n,int x,int y){
    for(int i=x+1,j=y;i<n;i++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x-1,j=y;i>=0;i--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x,j=y+1;j<n;j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x,j=y-1;j>=0;j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x+1,j=y+1;i<n && j<n;i++,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x+1,j=y-1;x<n && j>=0;i++,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=x-1,j=y-1;i>=0 &&j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }

    return true;
}


bool nQueen(int arr[100][100],int n,int i){
    if(i == n){
        cout<<"****************************"<<endl;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<arr[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<"****************************"<<endl;

    }

    for(int j=0;j<n;j++){
        if(isSafe(arr,n,i,j)){
            arr[i][j] = 1;
            nQueen(arr,n,i+1);
            arr[i][j]=0;
        }
    }
    // if(j==n){
    //     return;
    // }

    // if(isSafe(arr,n,i,j)){
    //     arr[i][j] = 1;
    //     nQueen(arr,n,++i,j);
    //     arr[i][j] = 0;
    // }
    // nQueen(arr,n,++i,j++);

    // cout<<"i= "<<i<<"  j= "<<j<<endl;
    // for(int key = 0; key<n ;key++){
    //     if(isSafe(arr,n,key,j)){
    //         arr[key][j]=1;
    //         nQueen(arr,n,0,j+1);
    //         arr[key][j] = 0;
    //     }
    // }
 
}

int main(){
    int arr[100][100] = {0};
    nQueen(arr,10,0);
}