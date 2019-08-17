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

 void printInorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    printInorder(root->left);//print the left node
       cout<<root->data<<" ";// then print the root
    printInorder(root->right);//then its right node
}
void print_kth_level(node * root,int k){
if(root==NULL){
    return ;
}
if(k==1){
    cout<<root->data<<" ";
    return;
}
print_kth_level(root->left,k-1);
print_kth_level(root->right,k-1);
return;
}
int height(node* root){
if(root==NULL){
    return 0;
}
int left=height(root->left);
int right=height(root->right);
return max(left,right)+1;
}
void printLevelByLevel(node* root){
for(int i=0;i<height(root);i++){
    print_kth_level(root,i);
    cout<<endl;
}
return;
}
bool is_bst(node* root ,int max=100000000,int min=-1000000000){
    if(root==NULL){
        return true;
    }
    if(root->data<max && root->data>min && is_bst(root->left,root->data,min) && is_bst(root->right,max,root->data)){
        return true;
    }
    else{
        return false;
    }
}

 int main(){
     node* root=bst();
     printInorder(root);
     printLevelByLevel(root);
     if(is_bst(root)){
         cout<<"yes";
     }
     else{
         cout<<"no this is not bst";
     }
 }
