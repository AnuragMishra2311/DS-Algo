// https://leetcode.com/problems/palindrome-linked-list/

/*
Using stack
Time Complexity : O(N)
Space Complexity : O(N)
*/

bool isPalindrome(ListNode* head) 
    {
        ListNode *temp=head;
        stack<int>s;
        while(temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        
        while(head)
        {
            int curr = s.top();
            if(head->val != curr)
                return false;
            s.pop();
            head = head->next;
        }
        return true;
    }


/*

Reverse the second half of linked list and then compare it with first half

Time Complexity : O(N)
Space Complexty : O(1)

*/

 ListNode* reverse(ListNode* head)
    {
        ListNode *prev = NULL, *next = NULL, *current = head;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

 ListNode *middle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while(slow and fast and fast->next and slow->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    return slow;
}
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode *mid = middle(head);
        ListNode *head_second_half = reverse(mid);
        while(head and head_second_half)
        {
            if(head->val != head_second_half->val)
                return false;

            head = head->next;
            head_second_half = head_second_half->next;
            
        }
        return true;
    }