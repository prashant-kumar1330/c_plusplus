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
 void topoSortHelper(T vertex,map<T,bool>& visited,list<T>& topo){
     visited[vertex]=true;
     
     for(auto x: addnode[vertex]){
       
         if(!visited[x]){
             topoSortHelper(x,visited,topo);
         }
     }
     topo.push_front(vertex);
 }
 void topologicalSort_dfs(T vertex){
   map<T,bool> visited;
   list<T> topo;
   topoSortHelper(vertex,visited,topo);
  for(auto x:topo){
      cout<<x<<",";
  }

 }
};
int main(){
graph<int>g;

g.addEdge(0,1);
g.addEdge(0,4);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(4,3);
g.addEdge(3,5);

g.topologicalSort_dfs(0);
}