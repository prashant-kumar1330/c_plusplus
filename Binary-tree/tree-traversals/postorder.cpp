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
//post order traverlsal
void printPostorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
   
    printPostorder(root->left);//first print the left node
    printPostorder(root->right);//then its right node
     cout<<root->data<<" ";//and after this print  the root 
}



int main(){
    node* root= BuildTree();
    printPostorder(root);

}