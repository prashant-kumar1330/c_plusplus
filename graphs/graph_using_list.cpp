#include<bits/stdc++.h>
using namespace std;

class graph{
 int V;
 list<int> *l;
 public:
  graph(int v){
  V=v;
  l= new list<int>[v];

  }

 void addEdge(int u,int v,bool biDirectional=true){
    l[u].push_back(v);
    if(biDirectional){
        l[v].push_back(u);
    }
 }

 void printList(){
     for(int i=0;i<V;i++){
       cout<<i<<"-> ";
       for(list<int>:: iterator it=l[i].begin();it!=l[i].end();it++){
           cout<<*it<<",";
       }
        cout<<endl;
     }
 } 

};
int main(){
graph g(7);
g.addEdge(0,1,0);
g.addEdge(0,2,0);
g.addEdge(0,3,0);
g.addEdge(1,4,0);
g.addEdge(2,3,0);
g.addEdge(2,4,0);
g.addEdge(3,4,0);
g.addEdge(5,6,0);
g.printList();
}