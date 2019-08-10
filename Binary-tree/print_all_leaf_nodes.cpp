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

void print_all_leaf_node(node* root){
    if(root->right==NULL && root->left==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    print_all_leaf_node(root->left);
    print_all_leaf_node(root->right);
    
    
}

   //4 5 6 -1 -1 7 8 -1 -1 9 10 -1 -1 -1 -1

int main(){
node* root=createBtree();
print_all_leaf_node(root);



}
