#include<iostream>
using namespace std;
struct node{
int data;
node* next;
};
 void print(node* head){
 node*it=head;
 while(it!=NULL){
    cout<<it->data<<" ";
    it=it->next;
 }
 }
void createlinklist(node*& head,int n){
int data;
 cin>>data;
     head=new node();
    head->data=data;
    head->next=NULL;
    node* it=head;
  while((n-1)!=0){
        cin>>data;

  node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    it->next=temp;
    it=it->next;
    n--;
  }
}
void k_append(node* &head,int k,int n){
    if(k==0||n<k||n==k){
        return;
    }
  node* fast=head;
  node* slow=head;
  for(int i=0;i<k;i++){
    fast=fast->next;
  }
   node* prev;
  while(fast!=NULL){
    fast=fast->next;
    prev=slow;
    slow=slow->next;
  }
  prev->next=NULL;
  node* it=slow;
  while(it->next!=NULL){
    it=it->next;
  }
  it->next=head;
  head=slow;


}
int main(){
node* head=NULL;
    int n;
    cin>>n;
    createlinklist(head,n);


  int k;
  cin>>k;

  k_append(head,k,n);
  print(head);
}
