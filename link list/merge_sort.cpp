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
node* midpoint(node *head){
node*fast=head->next;
node*slow=head;
while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
}
 return slow;

}
node* merge_two_sorted_link_list(node* head1,node* head2){
if(head1==NULL){
    return head2;
}
else{
        if(head2==NULL){
    return head1;
}
}
 node*c;
if(head1->data>head2->data){
     c=head2;
    c->next=merge_two_sorted_link_list(head1,head2->next);

}
else{
     c=head1;
    c->next=merge_two_sorted_link_list(head1->next,head2);

}
 return c;

}

 node *merge_sort(node* head){
 if(head==NULL||head->next==NULL){
    return head;
 }
 node* mid=midpoint(head);
 node* a=head;
 node* b=mid->next;
 mid->next=NULL;
  a=merge_sort(a);
  b=merge_sort(b);
 node* c=merge_two_sorted_link_list(a,b);
 return c;


 }

int main(){
node* head;
createlinklist(head);
print(head);
cout<<endl;
 node * b=merge_sort(head);
print(b);




}
