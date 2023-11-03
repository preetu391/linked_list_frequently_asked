struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Its an easy question as the list is sorted. Simply take a curr node and compare it with the next node, and if value matches just delete the curr->next node and do not move curr node forward and when value do not match simply traverse forward
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->val == curr->next->val)
        {
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
void main()
{
    return;
}