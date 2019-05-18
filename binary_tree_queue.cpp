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
//4 5 6 7 -1 9 8 -0 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1
node* buildtree(){
int data;
cin>>data;
node* root;
queue<node*> q;
if(data!=-1){
     root=new node(data);
    q.push(root);
}

while(!q.empty()){
    node* top=q.front();
    q.pop();
    cout<<"enter data for left node of "<<top->data<<" ";
    cin>>data;
    if(data!=-1){
       top->left=new node(data);
       q.push(top->left);
    }
   cout<<"enter data for right node of "<<top->data<<" ";
    cin>>data;
    if(data!=-1){
       top->right=new node(data);
       q.push(top->right);
    }

}
return root;
}
void inorder(node * root){
    if(root==NULL){
            return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void printleaf(node* root){
if(root==NULL){
    return;
}
if(root->right==NULL){
    cout<<root->data<<" ";
}
printleaf(root->left);
printleaf(root->right);


}
int main(){
  node* x=buildtree();
  inorder(x);
 cout<<endl;
  printleaf(x);
}
