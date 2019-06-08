#include<iostream>
using namespace std;
#include<stack>
 void reverse_my_stack(stack<int>& my_stack){
 int box;
 stack<int> helper;
 for(int i=0;i<my_stack.size();i++){
    int box=my_stack.top();
    my_stack.pop();
    int x=my_stack.size();
    for(int j=i;j<x;j++){
        helper.push(my_stack.top());
        my_stack.pop();
    }
    my_stack.push(box);
    while(!helper.empty()){
        my_stack.push(helper.top());
        helper.pop();
    }
 }
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
 reverse_my_stack(my_stack);
 while(!my_stack.empty()){
    cout<<my_stack.top()<<" ";

    my_stack.pop();
}
}
