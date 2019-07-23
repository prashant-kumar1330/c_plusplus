#include<iostream>
using namespace std;
template<typename T>
struct node{
T data;
node<T>* next;

};

template <typename T>
class deque{
node<T>* front;
node<T>* rear;
int n;
public:
    deque(){
    front=NULL;
    rear=NULL;
    n=0;
    }
    void push_front(T data){
    if(n==0){
        front= new node<T>;
        front->data=data;
        front->next=NULL;
        rear=front;
        n++;
    }
    node<T>* temp=new node<T>;
    temp->data=data;
    temp->next=front;
    front=temp;
    n++;
    }
    void pop_front(){
    if(n==0){
       return;
       }
       if(n==1){
        front==NULL;
        rear=NULL;
        n--;
        return;
       }
       node<T>* temp =front;
       front=front->next;
       delete temp;
       n--;

    }
    T top_front(){
    if(n==0){
        return NULL;
    }
    return front->data;

    }
    void push_back(T data){
    if(n==0){
        rear= new node<T>;
        rear->data=data;
        rear->next=NULL;
            front=rear;
            n++;
            return;
    }
    node<T>* temp=new node<T>;
    temp->data=data;
    temp->next=NULL;
    rear->next=temp;
    rear=temp;
    n++;

    }
    void pop_back(){
    if(n==0){
        return;
    }
    node<T>* temp=front;
    node<T>* backup;
    //we have to travel at the previous node of rear pointer to delete it it takes the comlexity of O(n);
    while(temp!=rear){
        backup=temp;
        temp=temp->next;
    }
    rear=backup;
    delete temp;

  n--;
    }

     T top_back(){
     if(n==0){
        return NULL;
     }
     return rear->data;
     }
    int size(){

    return n;
    }
};

int main(){
deque<int>s;
s.push_back(1);
cout<<s.top_front();
cout<<endl;
s.push_back(2);
s.push_back(3);
s.push_front(0);
cout<<s.top_front();
cout<<endl;
s.pop_front();
cout<<s.top_front();
cout<<endl;
cout<<s.top_back();
cout<<endl;
s.pop_back();
cout<<s.top_back();
cout<<endl;
cout<<s.size();



}
