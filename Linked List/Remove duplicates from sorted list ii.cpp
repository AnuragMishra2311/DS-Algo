/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Approach : Maintain a counter to keep a count of no of occurences of a particular element. Also keep track of previos node
if the counter for current element is 1, then make the prev node point to current node. 

Time Complexity : O(N)
Space Complexity : O(1)

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *prev = new ListNode(0);
        ListNode *dummy = prev;
        
        while(head)
        {
            int count = 1;
            int currentData = head -> val;
            
            while(head and head -> next and head -> next -> val == currentData)
            {
                head = head -> next;
                count += 1;
            }
            
            if(count == 1)
            {
                prev -> next = head;
                prev = head;
            }
            
            head = head -> next;
        }
         
        // set next of last node to NULL to mark the end of the list.
        prev -> next = NULL;
        return dummy -> next;
    }
};