#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
   node(data){
       this->data=data;
       left=NULL;
       right=NULL;
   }
};
node* buildtree(node* root){
int data;
cin>>data;
queue<node*> q;
if(data!=-1){
  root =new node(data);
  q.push(root);
}
while(!q.empty(){
   node* temp=q.front();
   
   
 
   if(temp->left!=NULL){

   }
})



}