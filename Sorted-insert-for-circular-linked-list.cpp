#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
Node *sortedInsert(Node *head, int data)
{
    Node *curr = head;
    Node *newnode = new Node(data);
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }
    if (head->next == nullptr)
    {
        if (head->data < data)
        {
            head->next = newnode;
            newnode->next = head;
            return head;
        }
        else
        {
            head->next = newnode;
            newnode->next = head;
            return newnode;
        }
    }
    while (true)
    {
        Node *temp = curr->next;
        if ((curr->next->data >= (newnode->data)) && (curr->data <= data))
        {
            curr->next = newnode;
            newnode->next = temp;
            break;
        }
        else if ((curr->next->data >= data) && (curr->data >= data))
        {
            curr->next = newnode;
            newnode->next = temp;
            swap(head->data, newnode->data);
            break;
        }
        curr = curr->next;
    }
    return head;
}
