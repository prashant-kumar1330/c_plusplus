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
struct Pair{
  int height;
  int diameter;
};
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
node* buildtree(){
int data;
cin>>data;
 node* root;
queue<node*> q;
if(data!=-1){
  root =new node(data);

}
 q.push(root);
while(!q.empty()){
   node* temp=q.front();
   q.pop();
   cout<<"enter data for the left node of "<<temp->data<<" and-1 to end"<<endl;
   cin>>data;
   if(data!=-1){
     node* left=new node(data);
     temp->left=left;
     q.push(temp->left);
   }
    cout<<"enter data for the right node of "<<temp->data<<" and-1 to end"<<endl;
   cin>>data;
   if(data!=-1){
     node* right=new node(data);
     temp->right=right;
     q.push(temp->right);
   }

}

 return root;

}

 Pair fastdiameter(node* root){
     Pair p;
    if(root==NULL){
       p.height=0;
       p.diameter=0;
       return p;
    }
    Pair left=fastdiameter(root->left);
    Pair right =fastdiameter(root->right);
    p.height=max(left.height,right.height) + 1 ;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;

}


int main(){
    node* root=buildtree();
    Pair p =fastdiameter(root);


    cout<<"height: "<<p.height<<endl;
    cout<<"diameter: "<<p.diameter;
}
