#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// approach 1 - which consumes space, in this approach we make a map to map old nodes to new nodes so that old nodes can be utilised to form our copy list
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    unordered_map<Node *, Node *> mp;
    while (temp)
    {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}
// approach 2 - without consuming space
// the idea of this approach is manipulating the pointers, so we do a three step process
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *curr = head;
    // Step 1 - Make copy of each node and place it just after the node which was copied
    while (curr)
    {
        Node *newnode = new Node(curr->val), *temp = curr->next;
        curr->next = newnode;
        newnode->next = temp;
        curr = newnode->next;
    }
    curr = head;
    // Step 2 - link the random pointers
    while (curr)
    {
        if (curr->random)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    // Step 3 - Separate the original and cloned lists
    Node *head2 = head->next;
    Node *clone = head2;
    // curr variable is for original list and clone is for cloned list
    for (curr = head; curr != nullptr; curr = curr->next)
    {
        curr->next = curr->next->next;
        clone->next = clone->next ? clone->next->next : nullptr;
        clone = clone->next;
    }
    return head2;
}

void main()
{
    return;
}