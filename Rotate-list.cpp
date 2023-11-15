struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// leverage the use of finding kth node from end, that is the point where the linked list have to be broken and connected before the rest of the linked list
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    if (k == 0)
        return head;
    ListNode *kth_node_from_end = nullptr, *curr = head, *prev = nullptr, *newhead = nullptr, *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    if (len == k || k % len == 0)
        return head;
    kth_node_from_end = calculate_kth_node_from_end(head, k % len);
    while (curr && curr->next)
    {
        if (curr->next == kth_node_from_end)
        {
            prev = curr;
        }
        curr = curr->next;
    }
    // now prev stores previous node of kth node from end and last node value is contained by curr node
    curr->next = head;
    prev->next = nullptr;
    newhead = kth_node_from_end;
    return newhead;
}
ListNode *calculate_kth_node_from_end(ListNode *head, int k)
{
    ListNode *slow = head, *fast = head;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->next;
}