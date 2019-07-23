#include<iostream>
using namespace std;
struct node{
 int data;
 node* next;
};

void create_circular_link_list(node*& head){
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
  temp->next=head;
}
void print(node * head){
    node* temp=head;

    do{
        cout<<head->data<<"-->";
        head = head->next;
    }
    while(head!=temp);
    cout<<"-1"<<endl;

}
void insert_at_head(node* &head,int data){
  node * temp=new node();
  temp->data=data;
  temp->next=head;
  node* c=head;
  do{
    c=c->next;
  }
  while(c->next!=head);
  //cout<<c->data;
  c->next=temp;
  head=temp;
}
void delete_node(node* &head,int k){

if(head->data==k){
  head=head->next;

}
node* temp=head;
node* prev=NULL;
while(temp->data!=k){
    prev=temp;
    temp=temp->next;
}
prev->next=temp->next;
delete temp;

}
int main(){
    node* head=NULL;
    create_circular_link_list(head);
    print(head);
    int k;
    cout<<"enter the value you want to add at the head: ";
    cin>>k;
    insert_at_head(head,k);
    print(head);
    cout<<endl;
    int x;
    cout<<"enter data you want to delete: ";
    cin>>x;
    delete_node(head,x);
    print(head);
}
