#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(int x,stack<int>& my_stack){
 if(my_stack.empty()){
    my_stack.push(x);
    return;
 }
int y=my_stack.top();
my_stack.pop();
insert_at_bottom(x,my_stack);
my_stack.push(y);

}

void reverse_my_Stack(stack<int>& my_stack){
if(my_stack.empty()){
    return;
}
int x=my_stack.top();
my_stack.pop();
reverse_my_Stack(my_stack);
insert_at_bottom( x, my_stack);

}

int main(){
 stack<int> my_stack;
 int data ;
 cout<<"enter data for the stack......and -1 for stop:"<<endl;
 cin>>data;
 while(data!=-1){
    my_stack.push(data);
    cin>>data;
 }
 reverse_my_Stack(my_stack);
 while(!my_stack.empty()){
    cout<<my_stack.top()<<" ";

    my_stack.pop();
}
}
