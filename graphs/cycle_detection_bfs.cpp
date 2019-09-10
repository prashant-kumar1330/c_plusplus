#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
 map<T,list<T>> addnode;
public:
graph(){


}

void addEdge(T u,T v,bool biDirectional=true){
     addnode[u].push_back(v);
     if(biDirectional){
            addnode[v].push_back(u);

     }

}
    void print(){
     for(auto x: addnode)
      {
          cout<<x.first<<"->";
          for(auto i: x.second){
              cout<<i<<",";
          }
          cout<<endl;
      }

    }
 void dfsHelper(T vertex,map<T,bool>& visited){
    visited[vertex]=true;
    cout<<vertex<<" ,";
    for(auto x: addnode[vertex]){
        if(!visited[x]){
            dfsHelper(x,visited);
        }

    }

 }

 void dfs(T vertex){
   map<T,bool> visited;
   int component=1;
   dfsHelper(vertex,visited);
   cout<<endl;
   for(auto i:addnode){
       T node= i.first;
       if(!visited[node]){
           dfsHelper(node,visited);
           component++;
       }
   }
   cout<<"this graph had "<<component<<" components";
 }
 bool cycleDetection(T vertex){
     map<T,bool> visited ;
     map<T,T> parent;
     queue<T> q;
     q.push(vertex);
     visited[vertex]=true;
     parent[vertex]=vertex;
     while(!q.empty()){
       T node=q.front();
       q.pop();
       for(auto neighbour: addnode[node]){
           if(visited[neighbour]&& parent[neighbour]!=node){
               return true;
           }
           else if(!visited[neighbour]){
               visited[neighbour]=true;
               parent[neighbour]= node;
               q.push(neighbour);
           }
       }
     }
     return false;
 }

};
int main(){
graph<int> g;
g.addEdge(0,1);
g.addEdge(0,4);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(4,3);
g.addEdge(3,5);

g.dfs(0);
cout<<endl;
graph<string> p;
p.addEdge("prashant","amit",1);
p.addEdge("aditya","shweta",1);
p.addEdge("prashant","anjali",1);
p.addEdge("jyoti","sumit",1);
p.addEdge("himanshu","prashant",1);

p.addEdge("himanshu","sumit",1);
p.addEdge("afsar","anjali",0);
p.addEdge("priyanka","aditya",0);
p.addEdge("mamta","shubham",1);
//g.print();
p.dfs("prashant");
cout<<endl;
if(p.cycleDetection("prashant")){
    cout<<"cycle is present";
}
else{
    cout<<"cycle is not present";
}


}
