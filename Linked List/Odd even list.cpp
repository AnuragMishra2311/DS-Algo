/*

https://leetcode.com/problems/odd-even-linked-list/

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, 
and return the reordered list.

Time complexity : O(N)
Space complexity : O(1)

*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL or head -> next == NULL or head -> next -> next == NULL)
            return head;
        
        ListNode *oddHead = head, *evenHead = head -> next;
        ListNode *save = evenHead;
        
        while(evenHead -> next and oddHead -> next)
        {
            oddHead -> next = evenHead -> next;
            oddHead = oddHead -> next;
            
            if(oddHead -> next)
            {
                evenHead -> next = oddHead -> next;
                evenHead = evenHead -> next;
            }
        }
        
        evenHead -> next = NULL;
        oddHead -> next = save;
        return head;
    }
};