#include<iostream>
using namespace std;
struct node{
int data;
node* left;
node* right;
node( int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};
 node* insertdata(node* root,int data){
     if(root==NULL){
         return new node(data);
     }
     if(data>=root->data){
         root->right=insertdata(root->right,data);
     }
     else{
          root->left=insertdata(root->left,data);
     }

 }

 node* bst(){
 int data;
 cout<<"enter root data ";
 cin>>data;
 node* root;
 if(data!=-1){
     root=new node(data);
 }
 else{
     cout<<"data invalid";
 }
 cout<<"enter data or -1 to stop ";
 cin>>data;
while(data!=-1){
    insertdata(root,data);
    cin>>data;
}
return root;
 }
node* search(node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    if(root->data<=data){
        search(root->right,data);
    }
    else{
        search(root->left,data);
    }
}
int main(){
    node* root=bst();
    //it takes O(logn) in an average case or O(h) in worst case where h is height of the tree
    node* temp=search(root,7);
    cout<<temp->data;
}
