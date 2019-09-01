#include<iostream>
#include<cstring>
#include"hastable.h"
using namespace std;

int main(){
 Hashtable<int> h(11);
 h.insert("mango",100);
 h.insert("apple",120);
  h.insert("banana",130);
   h.insert("chiku",140);
    h.insert("waterMelon",150);
     h.insert("papaya",160);
      h.insert("pears",170);
       h.insert("grapes",180);
        h.insert("avacado",200);
         h.display();
        cout<<endl;
        string fruit;
        cout<<"enter fruit name to know its price ";
        cin>>fruit;
        int* price=h.Search(fruit);
        if(price==NULL){
            cout<<"not found";
        }
        else{
            cout<<"price is => "<<*price<<endl;
        }
        cout<<"enter fruit name you want to delete ";
        cin>>fruit;
        h.deleteNode(fruit);
         cout<<endl;
       h.display();


}