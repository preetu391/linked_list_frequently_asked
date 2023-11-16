#include<bits/stdc++.h>
#include <iterator>
#include <list>
using namespace std;
//one way to solve this is to take a frequency array and marking for different values 0 and 1 within that key index. But if taken a large number of keys this would not be an efficient solution.
//When we study hashing then we see different approaches like using hash functions, there are many hash functions that can be formed so as to optimize the memory usage better. One of those is chaining in which we first calculate value given by hash function to make a fixed range and then using linked list chain that element to that index for later access
class MyHashSet {
public:
    vector<list<int>> v;
    int size;
    
    MyHashSet() {
        size=11;
        v.resize(size);
    }

    int hash(int key){
      return key%size;
    }

    list<int> :: iterator search(int key){
      int i = hash(key);
      return find(v[i].begin(),v[i].end(), key); 
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        v[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        v[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        return search(key)!=v[i].end();
    }
};
