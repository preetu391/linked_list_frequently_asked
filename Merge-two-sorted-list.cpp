struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Here we only have to utilise nodes given and just change their next pointers. To keep track of the resultant list take two pointers head and tail, head to point to the first element of the resultant linked list and tail for appending values in the linked list in sorted order
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = nullptr, *t = nullptr, *a = list1, *b = list2;
    if (list1 == nullptr && list2 != nullptr)
        return list2;
    if (list2 == nullptr && list1 != nullptr)
        return list1;
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;
    if (a->val < b->val)
    {
        head = a;
        t = a;
        a = a->next;
    }
    else
    {
        head = b;
        t = b;
        b = b->next;
    }
    while (a && b)
    {
        if (a->val < b->val)
        {
            t->next = a;
            a = a->next;
            t = t->next;
        }
        else
        {
            t->next = b;
            b = b->next;
            t = t->next;
        }
    }
    while (a)
    {
        t->next = a;
        a = a->next;
        t = t->next;
    }
    while (b)
    {
        t->next = b;
        b = b->next;
        t = t->next;
    }
    return head;
}