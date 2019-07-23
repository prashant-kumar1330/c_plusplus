#include<iostream>
#include<queue>
using namespace std;
template<typename T>

class stack {
queue<T> q1;
queue<T> q2;
public:
    bool empty(){
    if(q1.empty()&& q2.empty()){
        return true;
    }
   return false;
    }
    int size(){
    if(!q1.empty()){
        return q1.size();
    }
    return q2.size();
    }
    void push(T data){
    if(q1.empty()&&q2.empty()){
        q1.push(data);
    }
    else{
        if(!q1.empty()){
            q1.push(data);
        }
        else{
            q2.push(data);
        }
    }

    }
    void pop(){
    if(q1.empty()&& q2.empty()){
        return;
    }
    if(q1.empty()){
        int j=q2.size();
        for(int i=0;i<j-1;++i){
        q1.push(q2.front());
        q2.pop();
        }
        q2.pop();
    }
    else{
        int j=q1.size();
        for(int i=0;i<j-1;++i){
        q2.push(q1.front());
        q1.pop();
        }
        q1.pop();
    }

    }
    T top(){
    if(q1.empty()&& q2.empty()){
        return NULL;
    }

    if(q1.empty()){
        int j=q2.size();
        for(int i=0;i<j-1;++i){
        q1.push(q2.front());
        q2.pop();
        }
        T x=q2.front();
        q1.push(x);
        q2.pop();
        return x;

    }
    else{

        int j=q1.size();
        for(int i=0;i<j-1;++i){
        q2.push(q1.front());
        q1.pop();
        }
        T x=q1.front();

        q2.push(x);
        q1.pop();
        return x;

    }
    }


};
int main(){
stack<int> s;
for(int i=65;i<91;i++){
    s.push(i);
}

while(!s.empty()){
    cout<<s.top();
    cout<<endl;
    s.pop();
}

}
