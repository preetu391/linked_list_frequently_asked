#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//We just need to reach nth node from start and end and swap their values. one corner case need to be handled that is when k is equal to length of the linked list, then we need to simply swap the first and the last node
ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        int n=k;
        ListNode *first=head, *second=head, *slow=head, *fast=head, *prev=nullptr, *temp=head;
        int len=0;
        while(temp!=nullptr){
          len++;
          temp=temp->next;
        }
        int n2=k;
        while(n2--){
          prev=fast;
          fast=fast->next;
        }
        if(len==k){
          swap(head->val,prev->val);
          return head;
        }
        while(n>1){
          first=first->next;
          n--;
        }
        while(fast&&fast->next){
          slow=slow->next;
          fast=fast->next;
        }
        second=slow->next;
        swap(second->val, first->val);
        return head;
    }
    void main(){
        return;
    }