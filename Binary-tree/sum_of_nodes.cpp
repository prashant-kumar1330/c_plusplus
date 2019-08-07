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
 int sum_of_nodes(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left=NULL&&root->right==NULL){
        return root->data;
        cout<<"hello";
    }
    int x =sum_of_nodes(root->left);
    int y =sum_of_nodes(root->right);
    int temp=root->data;
    root->data= x+y;
    return root->data+temp;
}



int main(){
node* root=buildtree();
cout<<sum_of_nodes(root);


}
