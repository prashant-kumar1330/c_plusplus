#include <iostream>
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
node* BuildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root= new node(data);
    root->left=BuildTree(); //call for left part of the tree
    root->right=BuildTree();// call for right part of the tree
    return root; //finally return to root node to the main
    
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
    node* root= BuildTree();
    printInorder(root);

}