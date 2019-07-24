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
node * createBtree(){
    cout<<"Enter data and -1 if empty "<<endl;
    int data;
    cin>>data;
    node * root;
    if(data!=-1){
      root = new node(data);
    }
    queue<node * >q;
    q.push(root);
    while(!q.empty()){
        node * top = q.front();
        q.pop();
        cout<<"enter left data for "<< top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * left = new node(data);
            top->left = left;
            q.push(left);
        }
        cout<<"enter right data for "<< top->data<<" and -1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * right = new node(data);
            top->right = right;
            q.push(right);
        }
    }
    return root;
}
int height(node* root){
    if(!root){
        return 0;
    }
    int x= height(root->left);
    int y= height(root->right);
    return max(x,y)+1;
}
void printPreorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";//print the root 
    printPreorder(root->left);//then its left node
    printPreorder(root->right);//then its right node
}
int main(){
    node* root=createBtree();
 printPreorder(root);
 cout<<endl;
 cout<<height(root);
}