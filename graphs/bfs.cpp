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

  void bfs(T vertex){
  map<T,bool> visited;
   queue<T> q;
   q.push(vertex);
   visited[vertex]=true;
   while(!q.empty()){
    T top=q.front();
    cout<<top<<",";
    q.pop();
    
    for(auto x: addnode[top])
     if(!visited[x]){
         q.push(x);
         visited[x]=true;
     }

   }


  }

};
int main(){
graph<string> g;
g.addEdge("prashant","amit",1);
g.addEdge("aditya","shweta",1);
g.addEdge("prashant","anjali",1);
g.addEdge("jyoti","sumit",1);
g.addEdge("himanshu","prashant",1);

g.addEdge("himanshu","sumit",1);
g.addEdge("afsar","anjali",0);
g.addEdge("priyanka","aditya",0);
g.addEdge("mamta","shubham",1);
//g.print();
g.bfs("himanshu");
cout<<endl;
graph<int> gh;
gh.addEdge(0,1,0);
gh.addEdge(0,2,0);
gh.addEdge(0,3,0);
gh.addEdge(1,4,0);
gh.addEdge(2,3,0);
gh.addEdge(2,4,0);
gh.addEdge(3,4,0);
gh.addEdge(5,6,0);
gh.bfs(0);
}
