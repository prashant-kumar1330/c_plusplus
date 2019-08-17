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
 node* insertatTail(int data){
    node* head=NULL;
    node* it;
    node* temp;
    if(head==NULL){
        head=new node(data);
        it=head;
        temp=head;
    }
    node* p=new node(data);
    temp->right=p;
    return it;
}

node* bst_to_linklist(node* root){
    if(root==NULL){
        return NULL;
    }
    bst_to_linklist(root->left);
     node* head=insertatTail(root->data);
    bst_to_linklist(root->right);
    return head;
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
    node* head=bst_to_linklist(root);
    printList(head);
}
