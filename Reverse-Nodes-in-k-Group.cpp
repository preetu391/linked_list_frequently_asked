struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// A very pointer intensive question. We need to take care of the way the pointers are moving. Taking a dummy node makes the problem easier as the head node has to be changed.
//How dummy->next is pointing to new head?
//Initially dummy and pre are referencing the same address so any change made to prev->next will also be reflected in dummy->next but after  reversing the first group prev is  assigned to a complete new address. Therefore changes made to prev later do not affect the dummy->next as the latters job was over after first reversal itself.
ListNode *reverseKGroup(ListNode *head, int k)
{
    int count = 0;
    if (head == nullptr || k == 1)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *curr = dummy, *prev = dummy, *nex = dummy;
    while (curr->next != nullptr)
    {
        count++;
        curr = curr->next;
    }
    while (count >= k)
    {
        curr = prev->next;
        nex = curr->next;
        for (int i = 0; i < k - 1; i++)
        {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr; // pre is moving in a linear fashion
        count -= (k);
    }
    return dummy->next;
}
void main()
{
    return;
}
