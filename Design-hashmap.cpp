#include<bits/stdc++.h>
#include <iterator>
#include <list>
using namespace std;
//similar to design hashset
class MyHashMap {
public:
    vector<list<pair<int,int>>> v;
    int size;
    MyHashMap() {
        size=1000001;
        v.resize(size);
    }

    int hash(int key){
      return key%size;
    }

    list<pair<int,int>> :: iterator search(int key){
      int i = hash(key);
      list<pair<int,int>> :: iterator it = v[i].begin();
      while(it!=v[i].end()){
        if(it->first == key) return it;
      }
      return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it!=v[i].end()) remove(key);
        v[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it!=v[i].end()) return it->second;
        return -1;
    }
    
    void remove(int key) {
        int i=hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it!=v[i].end()) v[i].erase(search(key));
    }
};
