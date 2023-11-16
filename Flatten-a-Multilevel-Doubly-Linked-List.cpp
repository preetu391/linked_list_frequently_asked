class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
//Very easy question, just find not null child nodes and find their last node and insert the whole list between curr node and curr->next node
Node *flatten(Node *head)
{
    Node *curr = head, *temp = nullptr;
    while (curr)
    {
        if (curr->child)
        {
            temp = curr->next;
            Node *it = curr->child;
            curr->next = it;
            it->prev = curr;
            while (it->next)
            {
                it = it->next;
            }
            it->next = temp;
            if (temp)
                temp->prev = it;
            curr->child = nullptr;
        }
        curr = curr->next;
    }
    return head;
}
void main()
{
    return;
}
