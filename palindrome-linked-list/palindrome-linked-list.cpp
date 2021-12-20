class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL)
            slow = slow->next;
        
        ListNode *curr = slow;
        ListNode *prev = NULL;
        ListNode *next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        while(prev && head)
        {
            if(prev->val != head->val)
            {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
            
        
    }
};