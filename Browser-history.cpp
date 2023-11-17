#include<bits/stdc++.h>
using namespace std;
#include <iterator>
#include <list>
class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator curr;
    BrowserHistory(string homepage) {
        history.push_front(homepage);
        curr=history.begin();
    }
    
    void visit(string url) {
        //insert new node after the curr node
        curr++;
        curr = history.insert(curr,url);
        list<string> :: iterator it = curr;
        //now remove all nodes upto tail of linked list from the next of curr node
        it++;
        history.erase(it,history.end());
    }
    
    string back(int steps) {
        if(curr==history.end()) curr--;
        while((steps--)&&curr!=history.begin()){
          curr--;
        }
        return *curr;
    }
    
    string forward(int steps) {
        while((steps--)&&curr!=history.end()){
          curr++;
        }
        if(curr==history.end()) curr--;
        return *curr;
    }
};

