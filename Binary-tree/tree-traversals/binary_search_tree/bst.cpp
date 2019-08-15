#include<iostream>
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
node* BST(){
    cout<<"enter root data ";
    int data;
    cin>>data;
    if(data!=-1){
        node* root=new node(data);

    }
    else{
        cout<<"data invalid"
    }
    cout<<endl<<"enter data or -1 to stop "
    cin>>data;
    while(data!=-1){
        if(data>=root->data){
            root->right=new node(data);
        }
        else{
            root->left=new node(data);
        }
        cin>>data;
    }
    return root;
}
