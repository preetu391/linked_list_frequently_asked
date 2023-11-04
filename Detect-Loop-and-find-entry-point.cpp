struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head, *entry=head;
        if(head==nullptr||head->next==nullptr) return nullptr;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast){ //when loop found entry pointer and slow pointer are equal in distance
            while(entry!=slow){
            slow=slow->next;
            entry=entry->next;
          }
          return slow;
          }
        }
        return nullptr;
    }