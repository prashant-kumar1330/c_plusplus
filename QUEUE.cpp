#include<iostream>
using namespace std;
//circular queue;
template <typename T>
class queue{
T* arr;
int front;
int rear;
int max_size;
int curr_size;
public :
    queue(int n){
      front = 0;
      curr_size=0;
      max_size=n;
      rear =n-1;
      arr = new T[n];
    }
  bool is_full(){
 return curr_size==max_size;
}
void push( T data){
  if(is_full()){
    return ;
  }
  rear=(rear+1)% max_size;
  arr[rear]=data;
  curr_size++;

}
void pop(){
 if(is_empty()){
    return;
 }
 front= (front +1)% max_size;
 curr_size--;

}
bool is_empty(){
if(curr_size==0){
    return true;
}
return false;
}
int size(){
return curr_size;
}
T top(){
    if(is_empty()){
        return NULL;
    }
 return arr[front];

}

};
int main(){
queue<int> q(5);
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
cout<<q.top();
q.pop();
cout<<endl;
cout<<q.size();
cout<<q.is_empty()<<endl;
cout<<q.is_full();

}

