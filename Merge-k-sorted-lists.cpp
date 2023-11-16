#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// there are many ways we can solve this question.
// Approach 1 - Combine two lists at a time. Time complexity - O(nk) where n is total nodes of k list and k is number of lists
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
        head = merge_two(head, lists[i]);
    }
    return head;
}
ListNode *merge_two(ListNode *list1, ListNode *list2)
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
// Approach 2 - Use divide and conquer strategy. Divide the array of lists in two parts each time and start merging them in bottom up manner. Time complexity - O(nlogk)
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // using divide and conquer
    int k = lists.size();
    if (k == 0)
        return nullptr;
    if (k == 1)
        return lists[0];
    ListNode *head, *h1, *h2, *temp = nullptr;
    head = h1 = h2 = nullptr;
    h1 = merge(lists, 0, k / 2); // merge the first half linked lists
    if (k / 2 + 1 <= k - 1)
    {
        h2 = merge(lists, k / 2 + 1, k - 1); // merge second half linked lists
    }
    // merge linked lists obtained in h1 and h2
    if (!h1 && !h2)
        return head;
    if (h1 && !h2)
        return h1;
    if (h2 && !h1)
        return h2;
    if (h1->val < h2->val)
    {
        head = h1;
        temp = h1;
        h1 = h1->next;
    }
    else
    {
        head = h2;
        temp = h2;
        h2 = h2->next;
    }
    while (h1 && h2)
    {
        if (h1->val < h2->val)
        {
            temp->next = h1;
            h1 = h1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
            temp = temp->next;
        }
    }
    while (h1)
    {
        temp->next = h1;
        h1 = h1->next;
        temp = temp->next;
    }
    while (h2)
    {
        temp->next = h2;
        h2 = h2->next;
        temp = temp->next;
    }
    return head;
}
ListNode *merge(vector<ListNode *> &lists, int low, int high)
{
    if (low == high)
        return lists[low];
    int k = high - low + 1;
    ListNode *head, *h1, *h2, *temp = nullptr;
    head = h1 = h2 = nullptr;
    h1 = merge(lists, low, (low + (k / 2) - 1)); // recursively merge first half
    h2 = merge(lists, low + (k / 2), high);      // recursively merge second half
                                                 // merge linked lists obtained in h1 and h2
    if (!h1 && !h2)
        return head;
    if (h1 && !h2)
        return h1;
    if (h2 && !h1)
        return h2;
    if (h1->val < h2->val)
    {
        head = h1;
        temp = h1;
        h1 = h1->next;
    }
    else
    {
        head = h2;
        temp = h2;
        h2 = h2->next;
    }
    while (h1 && h2)
    {
        if (h1->val < h2->val)
        {
            temp->next = h1;
            h1 = h1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
            temp = temp->next;
        }
    }
    while (h1)
    {
        temp->next = h1;
        h1 = h1->next;
        temp = temp->next;
    }
    while (h2)
    {
        temp->next = h2;
        h2 = h2->next;
        temp = temp->next;
    }
    return head;
}
//Approach 3 - Using heap. So we'll take a min heap and store only head elements of the linked list and keep popping and mving heads until we obtain a whole new array. Time Complexity - O(nlogk)
class cmp{
  public:
  bool operator() (ListNode* a, ListNode* b){
    return a->val>b->val;
  }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* dummy = new ListNode(-1), *temp=nullptr;
        temp=dummy;
        for(int i=0;i<lists.size();i++){
          if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
          ListNode* smallest_node = pq.top();
          pq.pop();
          if(smallest_node->next) pq.push(smallest_node->next);
          temp->next = smallest_node;
          temp=temp->next;
        }
        return dummy->next;
    }
};
void main(){
    return;
}

