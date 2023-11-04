struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// in this problem we have to add two numbers whose digits are given in linked list and we have to return their sum in a linked list. The linked lists are given in reverse order so it becomes easy to start from the head of the linked lists and keep adding the digits. The carry has to be noted down.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;
    ListNode *newhead = nullptr;
    ListNode *newnext = newhead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry)
    {
        int x = 0;
        if (l1 && l2)
        {
            x = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1)
        {
            x = l1->val;
            l1 = l1->next;
        }
        else if (l2)
        {
            x = l2->val;
            l2 = l2->next;
        }
        x += carry;
        if (x >= 10)
        {
            x -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ListNode *newnode = new ListNode(x);
        if (newnext != nullptr)
        {
            newnext->next = newnode;
            newnext = newnode;
        }
        else
        {
            newnext = newnode;
            newhead = newnode;
        }
    }
    return newhead;
}
void main()
{
    return;
}