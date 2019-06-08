#include<iostream>
using  namespace std;
template<typename T>
struct node{
 T data ;
 node<T>* next;

};

template<typename T>
class stack{
node<T>* head=NULL;

int n=0;
 public:
     void push(T data){
       node<T>* it=head;
      head=new node<T>;
     head->data=data;
     head->next=it;
     n++;

     }
     void pop(){
         if(head==NULL){
            return;
         }
     node<T>* temp=head;
     head=head->next;
     delete head;
     n--;
     }

     int size(){
     return n;
     }
     bool isempty(){
     if(size()==0){
        return true;
     }
      return false;
     }
     T top(){
         if(head==NULL){
            return -1;
         }
     return head->data;
     }
};

int main(){
stack<char> s;
for(int i=65;i<91;i++){
    s.push(i);
}
while(!s.isempty()){
    cout<<s.top();
    cout<<endl;
    s.pop();
}

}
