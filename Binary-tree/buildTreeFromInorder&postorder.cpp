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
node* buildtree(int pre[],int in[],int strt,int end){
    static int i=0;
if(strt>end){
    return NULL ;
}
node* root=new node(pre[i]);
int index=-1;
for(int j=strt;j<=end;j++){
    if(pre[i]==in[j]){
        index=j;
 break;
    }

}
i++;
root->left=buildtree(pre,in,strt,index-1);
root->right=buildtree(pre,in,index+1,end);
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
    int pre[]={1,2,3,4,8,5,6,7};
    int in[]={3,2,8,4,1,6,7,5};
    int n=sizeof(in)/sizeof(int);
     node* root=buildtree(pre,in,0,n-1);
     printInorder(root);
     cout<<endl;
     printPreorder(root);

}
