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

class LRUCache : public Cache {
private:
    int count;
public:
    LRUCache(int cp): count(0){
        this -> cp = cp;
    }
    ~LRUCache(){
        while(count >0){
            Node * p = this -> head; 
            this -> head = p -> next;
            delete p;
            --count;
        }
    }

    void set(int key, int  value){
        map<int, Node * >::iterator it;
        if( (it=(this -> mp).find(key)) != (this -> mp).end()){
            //exist
            Node * p = it -> second;
            remove_node(*p);
            p -> prev = NULL;
            p -> next = NULL:
            p -> key = key; 
            p -> value = value;
            insert_head(*p);
        }else{
            //allocate a new cache
            if(this -> count < this->cp){
                Node * p = alloc_node(key, value);
                insert_head(*p);
            }else{
            //use the last node
                Node * p = this -> tail;
                remove_node(*p);
                p -> key = key;
                p -> value = value;
                insert_head(*p);
            }
        }
    }

    int get(int  key){
        map<int, Node *>:: iterator it = this -> mp.find(key);
        if(it != this -> mp.end()){
            return it -> second -> value;
        }else{
            return -1;
        }
    }

    void remove_node(Node & it){
        if(it.prev != NULL){
            it.prev -> next = it.next;
        }else{
            this -> head = it.next;
        }

        if(it.next != NULL){
            it.next -> prev = it.prev;
        }else{
            this -> tail = it.prev;
        }

        //remove map
        (this -> mp).erase(it.key);
    }

    void insert_head(Node & it){
        it.next = this -> head;
        it.prev = NULL;
        this -> head = &(it); 
        if(this -> tail == NULL){
            this -> tail = &(it);
        }

        //add map
         mp[it.key] = &(it);
    }

    Node * alloc_node(int key, int value){
        Node * p = new Node(key, value);
        ++count;
        return p;
    }

};



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
