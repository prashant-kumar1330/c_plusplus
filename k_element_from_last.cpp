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
int k_node_from_last(node* head,int key){
 node* fast=head;
 node* slow=head;
 for(int i=0;i<key;i++){
    fast=fast->next;
 }
 while(fast!=NULL){
    slow=slow->next;
    fast=fast->next;
 }

 return slow->data;


}




int main(){
  node* head=NULL;
  createlinklist( head);
  print (head);
  int k;
  cout<<endl;
  cout<<"enter the k_th element ";
  cin>>k;
  cout<<endl;
 cout<<k_node_from_last(head,k);
}
