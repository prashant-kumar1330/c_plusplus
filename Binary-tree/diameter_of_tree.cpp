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
int height(node* root){
    if(!root){
        return 0;
    }
    int x= height(root->left);
    int y= height(root->right);
    return max(x,y)+1;
}
// diameter is defined as the largest distance posiible between two nodes
int diameter(node* root){
  if(root==NULL){
    return 0;
  }
  int x=height(root->left);
  int y=height(root->right);
  int opt1=x+y;
  int opt2=diameter(root->left);

  int opt3=diameter(root->right);

  return max(opt1,max(opt2,opt3));
}



int main(){
    node* root=buildtree();
cout<<diameter(root);

}