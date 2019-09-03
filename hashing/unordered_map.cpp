#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int main(){

unordered_map <string,int> Mymap;
Mymap["mango"]=120;
Mymap["apple"]=110;
Mymap["banana"]=130;
Mymap["chiku"]=140;
for(auto i=Mymap.begin();i!=Mymap.end();i++){
    cout<<i->first<<" "<<i->second<<endl;
}
Mymap.at("mango") += 100; //this at function return refrence of the value
for(auto i=Mymap.begin();i!=Mymap.end();i++){
    cout<<i->first<<" "<<i->second<<endl;
}
cout<<Mymap.bucket("banana");

}
/*
unordered_map is an associated container that stores elements formed by combination of
 key value and a mapped value. The key value is used to uniquely identify the element
 and mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into
indices of hash table that is why performance of data structure depends on hash function a lot but
on an average the cost of search, insert and delete from hash table is O(1).
*/
