#include<iostream>
#include<queue>
using namespace std;
struct node{
int data;
node* left;
node* right;
node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};
node* buldTreeFromArray(int arr[],int start,int last){
if(start>last){
    return NULL;
}
int mid=(start+last)/2;
node* root=new node(arr[mid]);
root->left=buldTreeFromArray(arr,start,mid-1);
root->right=buldTreeFromArray(arr,mid+1,last);
return root;
}
void printInorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
 
    printInorder(root->left);//print the left node
       cout<<root->data<<" ";// then print the root 
    printInorder(root->right);//then its right node
}




int main(){
int arr[]={1,2,3,4,5,6,7};
node* root=buldTreeFromArray(arr,0,6);
printInorder(root);

}