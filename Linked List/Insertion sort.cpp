/*

https://leetcode.com/problems/insertion-sort-list/

*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *dummy = new ListNode(0);
        
        while(head)
        {
            ListNode *next = head -> next;
            ListNode *temp = dummy;
            
            while(temp -> next and temp -> next -> val < head -> val)
                temp = temp -> next;
            
            head -> next = temp -> next;
            temp -> next = head;
            head = next;
        }
        
        return dummy -> next;
    }
};