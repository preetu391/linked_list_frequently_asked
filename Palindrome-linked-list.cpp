struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//This question can be solved in various ways like by using stack, by reversing linked list and comparing it with original linked list etc. But the most efficient way to solve this question without using extra space is by using a trick, and that includes reaching to the mid element and reversing the list in place after mid element, then keep calculating using the mid element value and head element value
bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        if(head->next->next==nullptr) return head->val==head->next->val;
        ListNode* slow=head, *fast=head, *temp=head, *prev=nullptr;
        while(fast&&fast->next){
          slow=slow->next;
          fast=fast->next->next;
        }
        while(slow){
          temp=slow->next;
          slow->next=prev;
          prev=slow;
          slow=temp;
        }
        while(prev){
          if(prev->val!=head->val) return false;
          prev=prev->next;
          head=head->next;
        }
        return true;
    } 