/*

https://leetcode.com/problems/add-two-numbers/

Time Complexity : O(Max(len1, len2))
Space Complexity : O(Max(len1, len2))

*/

class Solution 
{
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        
        ListNode *prev = new ListNode(-1);
        ListNode *current, *head;
        
        int carry = 0, sum;
        bool first = true;
        
        
        while(l1 and l2)
        {
            
            sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
        
            current = new ListNode(sum);
            prev -> next = current;
            prev = current;
            
            if(first)
            {
                head = current;
                first = false;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1)
        {
            sum = l1 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            current = new ListNode(sum);
            prev -> next = current;
            prev = current;
            
            l1 = l1 -> next;
            
        }
        
        while(l2)
        {
            sum = l2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            current = new ListNode(sum);
            prev -> next = current;
            prev = current;
            
            l2 = l2 -> next; 
        }
        
        if(carry)
        {
            prev -> next = new ListNode(carry);
        }
        
        return head;
    }
};