#include<iostream>
using namespace std;
template<typename T>
struct node{
 node<T>* next;
 T data;

};
template<typename T>
class linklist{
 node<T>*head;
 int n=0;
 public:
     linklist<T>(){
      head=NULL;
    }
    // this function insert your data at the end of your list.
    void insert_at_tail(T data){
      if(head==NULL){
        head=new node<T>;
        head->data=data;
        head->next=NULL;
        n++;
        return;
      }
     node<T>* temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      node<T>* it=new node<T>;
      it->data=data;
      it->next=NULL;
      temp->next=it;
      n++;
    }

    // this function insert your data at the starting of your list.
    void insert_at_head(T data){
      if(head==NULL){
        head=new node<T>;
        head->data=data;
        head->next=NULL;
        n++;
        return;
    }
    node<T>* temp=new node<T>;
    temp->data=data;
    temp->next=head;
    head=temp;
    n++;
    }
    //this function print your list.
    void display(){
      node<T>* it=head;
      while(it!=NULL){
        cout<<it->data<<"-->";
        it=it->next;
      }

    }
    //this function gives you the size of your list.
    int size(){
        if(head==NULL){
            return 0;
        }
     return n;
    }
     // this function insert node at any position.
    void inser_at_given_position(T data,int position){
        if(position ==0||head==NULL){
            insert_at_head(data);
        }
        else{
        if(position>=size()){
            insert_at_tail(data );
        }
        }
      node<T>* temp=head;
      int x=1;
      while(x<=position-1){
        temp=temp->next;
        x++;
      }
      node<T>* it=new node<T>;
      it->data=data;
      it->next=temp->next;
      temp->next=it;
      n++;
    }
    //this function delete node at any position
 void delete_node(int position){
 if(head==NULL){
    return;
 }
 if(position>size()){
    cout<<"ERROR"<<endl;
    return;
 }
 if(position==0){
    node<T>* temp=head;
    head=head->next;
    delete temp;
    n--;
    return;
 }
   node<T>* current=head;
   node<T>* after;
   for(int i=1;i<position-1;i++){
    current=current->next;
   }
   after=current->next;
   current->next=after->next;
   delete after;
   n--;
 }
 // this function gives you the head of the your list.
 node<T>* give_me_head(){
   return head;
 }
 //this function search data in your list.
 bool search_data(int key){
  node<T>* temp=head;
  while(temp!=NULL){
    if(temp->data==key){
        return true;
    }
    else{
        temp=temp->next;;
    }

  }
    return false;
 }
 // this function will reverse the linked list.
 void reverse_list(){
 node<T>* n;
 node<T>* prev=NULL;
 node<T>* curr=head;

   while(curr!=NULL){
    n=curr->next; //this will save the add of next node
    curr->next=prev;  //this will change the pointers
    //then update the pointers

    prev=curr;
    curr=n;

   }
   head=prev;

   return;
 }

};

int main(){
 linklist<int> mylist;
 mylist.insert_at_tail(1);
 mylist.insert_at_tail(2);
 mylist.insert_at_tail(3);
mylist.insert_at_tail(4);
mylist.insert_at_tail(5);
mylist.insert_at_tail(6);
mylist.insert_at_head(0);
mylist.inser_at_given_position(12,2);
mylist.display();
cout<<endl;
cout<<mylist.size()<<endl;;
mylist.delete_node(0);
mylist.display();
cout<<endl;
cout<<mylist.size()<<endl;
cout<<mylist.search_data(4)<<" "<<mylist.search_data(7)<<endl;
mylist.reverse_list();
mylist.display();
cout<<endl;


}

