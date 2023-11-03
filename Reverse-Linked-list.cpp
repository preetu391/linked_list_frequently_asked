struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Can be solved iteratively as well as recursively
// iterative approach - Very easy, as we only need to keep changing the next pointer and pointing towards the previous node to the current node.
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (temp != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}
// recursive approach 1 - In this approach we take head node and recursively reverse the rest of the linked list and return its head
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *rest_head = reverseList(head->next);
    ListNode *rest_tail = head->next;
    rest_tail->next = head;
    head->next = nullptr;
    return rest_head;
}
// recursive approach 2 - in this approach we reverse from start upto ith node
ListNode *recur(ListNode *curr, ListNode *prev)
{
    if (curr == nullptr)
        return prev;
    ListNode *next = curr->next;
    curr->next = prev;
    return recur(next, curr);
}