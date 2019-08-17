#include<iostream>
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
node* head=NULL;
 void insert_at_tail(int data){
      if(head==NULL){
        head=new node(data);

        return;
      }
     node* temp=head;
      while(temp->right!=NULL){
        temp=temp->right;
      }
      node* it=new node(data);

      temp->right=it;

    }
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

node* bst_to_linklist(node* root){
    if(root==NULL){
        return NULL;
    }
    bst_to_linklist(root->left);
    //this is inorder traversal
    insert_at_tail(root->data);
    bst_to_linklist(root->right);

}

void printList(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->right;
    }
    cout<<"-1";
}
int main(){
    node* root=bst();
    bst_to_linklist(root);
    printList(head);
}
