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
node* bst_deletion(node* root,int data){
    if(root==NULL){
        return NULL;
    }
    else if (root->data>data)
    {  //call for left part of the tree
       root->left=bst_deletion(root->left,data);
       return root;
    }
    else if (root->data==data)
    {
       // 3 condition is there 
       //1st when the node which we want to delete is leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2nd when one side of the node is null
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
             return temp;
        }
        if(root->right==NULL && root->left!=NULL){
            node* temp=root->left;
            delete root;
             return temp;
        }
        //3rd when none of the side is null
        if(root->left&&root->right){
            node* replace=root;
            while(replace!=NULL){
                // we are finding samllest node of right sub tree
                replace=replace->left;
            }
            root->data=replace->data;
            root->right=bst_deletion(root->right,replace->data);
        }

    }
    else{
        root->right=bst_deletion(root->right,data);
       return root;
    }
}

 int main(){
     node* root=bst();
     printInorder(root);
     printLevelByLevel(root);
     root=bst_deletion(root,7);
     cout<<endl;
     printInorder(root);
     printLevelByLevel(root);
 }
