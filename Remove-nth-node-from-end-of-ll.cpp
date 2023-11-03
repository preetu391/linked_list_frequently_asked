struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// The intuition to solve this question is to take two pointers. Let's name them first and second. So first pointer will be at head initially and second pointer will stand at the nth node from the first node. Thus when second pointer reaches null the first pointer would be standing at the nth node from the end of the linked list
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *first = head;
    ListNode *second = head;
    ListNode *prev = head;
    int nn = n;
    if (head->next == nullptr)
        return nullptr;
    while (nn--)
    {
        second = second->next;
    }
    int m = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        m++;
    }
    while (second != nullptr)
    {
        prev = first;
        first = first->next;
        second = second->next;
        m++;
    }
    if (n == m)
    {
        head = head->next;
        return head;
    }
    prev->next = first->next;
    return head;
}
void main()
{
    return;
}