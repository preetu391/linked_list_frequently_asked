struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
// Here we need to handle one corner case that might get missed is when slow and fast meet at the head node, then we cannot make head point to null, so we have to again iterate in the cycle and find the previous node to the head and change its next pointer to null.
void removeLoop(Node *head)
{
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        if (slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast)
    {
        slow = head;
        if (slow == fast)
        {
            while (fast->next != slow)
                fast = fast->next;
        }
        else
        {
            while (fast->next != slow->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = nullptr;
    }
}
void main()
{
    return;
}