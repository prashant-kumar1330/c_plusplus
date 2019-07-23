#include<iostream>
#include<stack>
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

node* k_reverse(node* head,int k){
    stack<node*> box;
 node* current=head;
 node* prev=NULL;
 while(current!=NULL){
   int cnt=0;
   while(current!=NULL&&cnt<k){
     box.push(current);
     current=current->next;
     cnt++;
   }
   while(box.size()>0){
    if(prev==NULL){
        prev =box.top();
    head=prev;
        box.pop();

    }
    else{
        prev->next=box.top();

        prev=prev->next;
        box.pop();
    }
   }
 }
 prev->next=NULL;
 return head;
}

int main(){
 node* head=NULL;
  int n;
  cin>>n;

 createlinklist(head,n);
 print(head);
 cout<<endl;
 cout<<"enter the value of k: ";
 int k;
 cin>>k;

  node* newhead=k_reverse(head,k);
 print(newhead);
}
