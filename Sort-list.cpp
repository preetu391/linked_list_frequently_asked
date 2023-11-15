struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//In this question we can use any sorting algorithm we want to, but the best time complexity is given by merge sort. Also when we sort linked list alike arrays we don't just swap values but whole nodes.
ListNode *sortList(ListNode *head)
{
    return mergeSort(head);
}
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *t = nullptr, *head = nullptr;
    if (!l1 && !l2)
        return nullptr;
    if (l1 && !l2)
        return l1;
    if (l2 && !l1)
        return l2;
    if (l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    t = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        else
        {
            t->next = l2;
            l2 = l2->next;
            t = t->next;
        }
    }
    while (l1)
    {
        t->next = l1;
        l1 = l1->next;
        t = t->next;
    }
    while (l2)
    {
        t->next = l2;
        l2 = l2->next;
        t = t->next;
    }
    return head;
}
ListNode *findMid(ListNode *head)
{
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeSort(ListNode *head)
{
    // base case of recursion
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *left = head, *right = nullptr;
    // calculate mid pointer and break the array in two parts
    ListNode *mid = findMid(head);
    right = mid->next;
    mid->next = nullptr;
    // recursively sort the two parts
    left = mergeSort(left);
    right = mergeSort(right);
    // combine or merge both sorted lists;
    ListNode *result = merge(left, right);
    return result;
}
void main()
{
    return;
}