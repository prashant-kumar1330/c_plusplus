#include <iostream >
#include <cstring>
using namespace std;

template <typename T>
class node
{
public:
   string key;    // stores key
   int value;     // stores value
   node<T> *next; // stores address of next node
   // construtor
   node(string k, int v)
   {
      this->key = k;
      this->value = v;
   }
   ~node(){
     if(next!=NULL){
        delete next;
     }

   }
};
template <typename T>
class Hashtable
{
   int currentSize;
   int tableSize;
   node<T> **buckets; //stores the refrence of array which stores the address
   void rehash(){
    node<T>** oldBuckets=buckets;
    int oldTableSize=tableSize;
    tableSize=2*tableSize;
    currentSize=0;
    buckets=new node<T>*[tableSize];
     for (int i = 0; i < tableSize; i++)
      {
         buckets[i] = NULL;
      }
    for(int i=0;i<oldTableSize;i++){
        node<T>* temp=oldBuckets[i];

        if(temp!=NULL){
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;

            }
            delete oldBuckets[i];



        }


    }
 delete [] oldBuckets;//delete the arrays

return;

   }
public:
   Hashtable(int defaultSize = 7)
   {
      this->currentSize = 0;
      tableSize = defaultSize;            //initialize the table size by default size
      buckets = new node<T> *[tableSize]; // makes an  dynamic array of addresses
      // initialize all the index by a NULL pointer
      for (int i = 0; i < tableSize; i++)
      {
         buckets[i] = NULL;
      }
   }

   int hashFunction(string k)
   {
      int l = k.length();
      int ans = 0;
      int power = 1; // 37^0=1 at starting
      for (int i = 0; i < l; i++)
      {
         ans += k[l - 1 - i] * power;
         power *= 37;
         power %= tableSize;
         ans %= tableSize;
      }
      return ans;
   }

   void insert(string k, int val)
   {
      int index =  this->hashFunction(k); // hashFUnction will return an index where we will stores the address of our  node
      node<T> *temp = new node<T>(k, val);
      temp->next = buckets[index];
      buckets[index] = temp;
      currentSize++;
      float loadFactor=(float)currentSize/tableSize;
      if(loadFactor>0.7){
            cout<<"load factor is "<<loadFactor<<endl;
        rehash();
      }
      return;
   }
   T* Search(string k){
    int index=this->hashFunction(k);
    node<T>* temp=buckets[index];
    while(temp!=NULL){
        if(temp->key==k){
            return &(temp->value);
        }
        temp=temp->next;


   }
   return NULL;

   }
   void deleteNode(string k){
    int i= this->hashFunction(k);
   node<T>* temp=buckets[i];
   if(temp->key==k){
    buckets[i]=temp->next;
    delete temp;
    currentSize--;
    return;
   }
   node<T>*it=temp;
   temp=temp->next;
   while(temp!=NULL){
       if(temp->key==k){
        it->next=temp->next;
        delete temp;
        currentSize--;
        return;
       }
    it=temp;
    temp=temp->next;
   }
   cout<<"entered data is not found";

   }

   void display()
   {


      for (int i = 0; i < tableSize; i++)
      {
         node<T> *temp = buckets[i];
         cout << "bucket " << i << "->";
         while (temp != NULL)
         {
            cout << temp->key <<" price => "<<temp->value<<"||";
            temp = temp->next;
         }
         cout << endl;
      }
      return;
   }
};
