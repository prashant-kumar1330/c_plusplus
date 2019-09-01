#include<iostream>
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
       cout<<"price of pears =>"<< h.Search("pears");




}
