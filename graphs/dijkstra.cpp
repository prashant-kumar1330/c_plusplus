#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    map<T,list<pair<T,int>>> m;
 public:
 graph(){


}
 void addEdge(T u,T v,int weight, bool biDirectional=true){
     m[u].push_back(make_pair(v,weight));
     if(biDirectional){
       m[v].push_back(make_pair(u,weight));
     }

 }
 void print(){
        //Let try to print the adj list
        //Iterate over all the key value pairs in the map
        for(auto j:m){

            cout<<j.first<<"->";

            //Iterater over the list of cities
            for(auto l: j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";

            }
            cout<<endl;
        }

    }
    void Dijkstra(T src){
        map<T,int> distance;
        for(auto j:m){
            distance[j.first]=100000000;// set it infinity
        }
        set<pair<int,T>>s;
        distance[src]=0;
        s.insert(make_pair(distance[src],src));
        while(!s.empty()){
            auto p=*(s.begin());
            T node=p.second;
            int nodeDistance=p.first;
            s.erase(s.begin());

            for(auto neighbour: m[node]){
                if(nodeDistance + neighbour.second< distance[neighbour.first]){
                    T destination=neighbour.first;
                    auto f=s.find(make_pair(distance[destination],destination));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    distance[destination]=nodeDistance+ neighbour.second;
                    s.insert(make_pair(distance[destination],destination));
                }

            }
        }
          for(auto d:distance){
            
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }
};
int main(){
  graph< string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    //india.print();
     india.Dijkstra("Amritsar");

}
