#include<bits/stdc++.h>
using namespace std;
//we take a doubly linked list as doubly linked list is the data structure that helps us to add and remove in O(1) time complexity. 
//get and put functionality is sorted now, so for we'll store the last recent after head and the least recent before tail. 
//we'll also maintain a map that helps keep track of the existing nodes and also helps in addition and deletion of nodes
class LRUCache {
public:
    class Node{
      public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node (int keyy, int vall){
          key = keyy;
          val = vall;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode){
      Node* temp=head->next;
      newnode->next=temp;
      newnode->prev=head;
      head->next=newnode;
      temp->prev=newnode;
    }

    void deletenode(Node* delnode){
      Node* delprev = delnode->prev;
      Node* delnext = delnode->next;
      delprev->next=delnext;
      delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
          Node* result_node = mp[key];
          int result = result_node->val;
          mp.erase(key);
          deletenode(result_node); //delete node from its original place
          addnode(result_node); //add it just after head node, as most recent element has to be added just after head
          mp[key] = head->next; //now map the new address to the given key
          return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
          Node* existingnode = mp[key]; //if we are trying to put the same key then we have to first remove it and then add it after head as it becomes the last recently used key
          mp.erase(key);
          deletenode(existingnode);
        }
        if(mp.size()==cap){
          mp.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        mp[key]=head->next;
    }
};
