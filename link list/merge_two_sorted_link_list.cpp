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
int main(){

node* head1;
node* head2;
createlinklist(head1);
createlinklist(head2);
print(head1);
cout<<endl;
print(head2);
cout<<endl;
head1=merge_two_sorted_link_list(head1,head2);
print(head1);

}
