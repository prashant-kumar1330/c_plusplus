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
};
template <typename T>
class Hashtable
{
   int currentSize;
   int tableSize;
   node<T> **buckets; //stores the refrence of array which stores the address
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
      return;
   }
   int Search(string k){
    int index=this->hashFunction(k);
    node<T>* temp=buckets[index];
    while(temp!=NULL){
        if(temp->key==k){
            return temp->value;
        }
        temp=temp->next;


   }

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
