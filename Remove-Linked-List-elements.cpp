struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// This question can be solved using recursion and iteratively
// iterative solution ahead - it includes generalising the question by adding a dummy node before the head node to save the work of exclusively handling the head node deletion case
ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *curr = dummy;
    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->val == val)
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
    return dummy->next;
}
// recursive solution ahead - The idea and intuition of solving this question recursively is that standing at a particular node all we need to check is head value, so if it's equal to val then simply return the next node and recurse for rest of the linked list and if head node value is not equal to val return the head simply
ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    head->next = removeElements(head->next, val);
    if (head->val == val)
    {
        return head->next;
        delete head;
    }
    else
    {
        return head;
    }
}
void main()
{
    return;
}
