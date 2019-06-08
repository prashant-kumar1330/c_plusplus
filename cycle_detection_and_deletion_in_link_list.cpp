#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;
};
void createlinklist( node*& head){
    int data;
    cin>>data;
    if(data!=(-1)){
        head= new node();
        head->data =data;
        head-> next=NULL;
    }
    node*it =head;
    cin>>data;
    while(data!=(-1)){
        node* temp=new node();
        temp-> data=data;
        temp->next=NULL;
        it->next=temp;
        it=it->next;
        cin>>data;

    }
}
void print(node * head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"-1"<<endl;

}
bool is_cycle(node* head){
node* fast=head;
node* slow=head;
while(fast!=NULL&&fast->next!=NULL){
    if(fast==slow){
        return true;
    }
    fast=fast->next->next;
    slow=slow->next;
}
return false;

}
void remove_cycle(node* head){
node* fast=head;
node* slow =head;
do{
    fast=fast->next->next;
    slow=slow->next;
}
while(slow==fast);
slow=head;
node* last;
while(slow==fast){
    last=fast;
    fast=fast->next;
    slow=slow->next;
}
last->next=NULL;



}
int main(){
  node* head=NULL;
  createlinklist(head);
  print(head);
  cout<<endl;
 cout<<is_cycle(head);
 remove_cycle(head);

}
