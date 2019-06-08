#include<iostream>
using namespace std;
struct node{
int data;
node* next;
};


void createlinklist(node*& head){
  int data;
  cin>>data;
  if(data!=-1){
    head=new node();
    head->data=data;
    head->next=NULL;
  }
  node* temp=head;
  cin>>data;
  while(data!=-1){
    node* it=new node();
    it->data=data;
    it->next=NULL;
    temp->next=it;
    temp=temp->next;
    cin>>data;
  }
}

void print(node* head){
 while(head!=NULL){
    cout<<head->data<<"-->";
    head=head->next;
 }
}

node* reverse_mylist(node* head){
if(head==NULL||head->next==NULL){
    return head;
}
node* newhead=reverse_mylist(head->next);
node* current=head;
current->next->next=current;
current->next=NULL;
return newhead;

}

int main(){
 node* head;
 createlinklist(head);
 print(head);
 node* newhead=reverse_mylist(head);
 cout<<endl;
 print(newhead);



}
