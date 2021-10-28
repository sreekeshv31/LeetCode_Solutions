/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(headA || headB)
        {
            if(headA==headB)
                return headB;
            if(!headA)
                headA = p2;
            else
                headA = headA->next;
            if(!headB)
                headB = p1;
            else
                headB = headB->next;
        }
        return headB;
        
    }
};