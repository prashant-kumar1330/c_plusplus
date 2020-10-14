#include <iostream>
#include<map>
#include<unordered_map>
#include<cstring>
#include<list>
using namespace std;
template <typename T>
class Graph{
    int V;
    unordered_map<T, list<T> > adjList;
public:
    Graph(int v){
        V = v;
    }
    void addEdge(T u, T v) {
        adjList[u].push_back(v);
    }
    
    // TODO: Check if graph is directed and acyclic or not.

    void dfsUtil(T src, unordered_map<T, bool> &visited, list<T> &topoSort){
        visited[src] = true;

        for(auto neighbour: adjList[src]){
            if(not visited[neighbour])
                dfsUtil(neighbour, visited, topoSort);
        }
        topoSort.push_front(src);
        return;

    }
    void dfs(){
        unordered_map<T, bool> visited;
        list<T> topoSort;
        for(auto node: adjList){
            T key = node.first;
            visited[key] = false;
        }

        for(auto node: adjList){
            T key = node.first;
            if(not visited[key]){
                dfsUtil(key, visited, topoSort);
            }
            
        }
        //cout<<"Number of components : "<<count;
        for(auto element: topoSort){
            cout<<element<<" ";
        }
    }
};
int main() {
    Graph<string> g(5);
    g.addEdge("Jaipur","Rewari");
    g.addEdge("Jammu","Delhi");
    g.addEdge("Agra", "Jaipur");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Delhi","Rewari");
    g.dfs();

}
