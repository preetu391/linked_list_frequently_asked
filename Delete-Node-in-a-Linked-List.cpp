struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Easy if the trick clicks. Trick is to copy the value in the next node in the node given and deleting the next node
void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}
void main()
{
    return;
}