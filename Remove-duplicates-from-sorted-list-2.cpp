#include<bits/stdc++.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Use a hashmap to store the values of the nodes that occur more than one time in one traversal of the linked list and in the next traversal remove all nodes with frequency >1
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        map<int,int> m;
        if(head==nullptr||head->next==nullptr) return head;
        while(temp!=nullptr){
          m[temp->val]++;
          temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr&&temp->next!=nullptr){
          if(m[temp->next->val]>1){
            temp->next = temp->next->next;
          }else{
            temp=temp->next;
          }
        }
        if(m[head->val]>1) return head->next;
        return head;
    }
void main(){
    return;
}