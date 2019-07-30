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
int main(){
    node* root=createBtree();
    
 int k;
  cout<<endl;
 cout<<"enter level ";
 cin>>k;
cout<<endl;
print_kth_level(root,k);

 
}
