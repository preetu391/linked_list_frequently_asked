struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Observe carefully where each pointer needs to point, so for each odd placed node as well as even placed node we have to make their next pointers point to next of next node and keep the track of the evenhead node and link both these segragations of the linked list by linking evenhead and the curr pointer which after the iterations is pointing at the last node of the odd indices
ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return head;
        ListNode* evenhead= head->next, *curr=head, *nex=curr->next;
        while(nex!=nullptr&&nex->next!=nullptr){
          curr->next = nex->next;
          nex->next=nex->next->next;
          curr=curr->next;
          nex=nex->next;
        }
        curr->next = evenhead;
        return head;
    }
    void main(){
        return;
    }