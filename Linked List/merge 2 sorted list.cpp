/*

https://leetcode.com/problems/merge-two-sorted-lists/

Approach : Maintain a prev pointer and for every iteration make the next of prev node point to smaller of two nodes 
           we are currently comparing.

Time Complexity : O(max(M, N))
Space Complexity : O(1)

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *save, *chota;
        ListNode *prev = new ListNode(0);
        save = prev;
        
        while(list1 and list2)
        {
            if(list1 -> val < list2 -> val)
            {
                chota = list1;
                list1 = list1 -> next;
            }
            
            else
            {
                chota = list2;
                list2 = list2 -> next;
            }
            
            prev -> next = chota;
            prev = chota;
        }
        
        
        while(list1)
        {
            prev -> next = list1;
            prev = list1;
            list1 = list1 -> next;
        }
        
        while(list2)
        {
            prev -> next = list2;
            prev = list2;
            list2 = list2 -> next; 
        }
        
        return save -> next;
    }
};