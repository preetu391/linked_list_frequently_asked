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
// If we look at it with a mathematical perspective it becomes very easy, we are given two intersected lists, that tells us that after some node the linked lists are same, thus by calculating their lenghts and making the bigger list come to abs(cnt1-cnt2) we will be some x distance away from the intersection point for both the linked lists, thus we can easily traverse in both lists and find the intersection point
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int cnt1 = 0, cnt2 = 0;
    ListNode *tmp1 = headA, *tmp2 = headB;
    while (tmp1)
    {
        cnt1++;
        tmp1 = tmp1->next;
    }
    while (tmp2)
    {
        cnt2++;
        tmp2 = tmp2->next;
    }
    int diff = abs(cnt1 - cnt2);
    if (cnt1 > cnt2)
    {
        while (diff--)
        {
            headA = headA->next;
        }
    }
    else
    {
        while (diff--)
        {
            headB = headB->next;
        }
    }
    while (headA && headB)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}