class Solution {
public:

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {
        
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

       
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* newHead = reverseList(slow->next);

        
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reverseList(newHead);   
                return false;
            }

            first = first->next;
            second = second->next;
        }

       
        reverseList(newHead);

        return true;
    }
};