/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        auto dummy = ListNode{0};
        
        while(head)
        {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
        
    }
};