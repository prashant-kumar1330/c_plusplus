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
class hbpair{
public:
int height;
bool balance;
};
// a tree is balanced when diffrence between its left sub-tree and right-subtree is less than or equal to 1
hbpair isHeightBalance(node* root){
    hbpair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    hbpair left=isHeightBalance(root->left);
    hbpair right =isHeightBalance(root->right);
   p.height=max(left.height,right.height) +1;
   if(abs(left.height-right.height)<=1 && left.balance && right.balance){
       p.balance=true;
   }
   else{
        p.balance=false;
      
   }
    return p;
}
int main(){
    node* root=createBtree();
    if(isHeightBalance(root).balance){
        cout<<"yes this tree is balanced";
    }
    else{
        cout<<"no this is not a balanced tree";
    }
}