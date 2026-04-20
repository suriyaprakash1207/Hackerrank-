#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
typedef class LRUCache : Cache
{
    public:
        LRUCache(int capacity) { cp = capacity; tail = NULL; head = NULL; }
         
        void set(int key, int value)
        {
            Node* placeholder = NULL;
            
            // Update if found
            if (mp.find(key) != mp.end())
            {
                placeholder = mp[key];
                placeholder->value = value;
                
                // Stitching linked list
                if (placeholder->prev != NULL)
                    placeholder->prev->next = placeholder->next;
                
                if (placeholder->next != NULL)
                    placeholder->next->prev = placeholder->prev;
            } else // if not found
            {
                placeholder = new Node(NULL, NULL, key, value);
                mp[key] = placeholder;
            }
            
            // Updating head as the latest update/addition
            if (head != NULL) head->prev = placeholder;
            head = placeholder;
            
            if (tail == NULL) tail = placeholder;
            
            if (mp.size() > cp)
            {
                placeholder = tail;
                tail = tail->prev;
                tail->next = NULL;
                
                mp.erase(placeholder->key);
                
                delete placeholder;
            }
        }
        
        int get(int key)
        {
            if (mp.find(key) == mp.end()) return -1;
            
            Node* placeholder = mp[key];
            
            if (placeholder->prev != NULL)
                placeholder->prev->next = placeholder->next;
            
            if (placeholder->next != NULL)
                placeholder->next->prev = placeholder->prev;
            
            if (head != NULL)
                head->prev = placeholder;
            
            head = placeholder;
            return placeholder->value;
        }
} LRUCache;
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
