/*

Approach : Step 1. Split list into 2 parts 
                if len(list) = even, divide it into 2 equal parts.
                if len(list) = odd, second part will have an extra node.


            Step 2. Reverse 2nd part of list.

            Step 3. Now, headOfFirst will point to headOfSecond and so on.


Time Complexity : O(N) to find middle element.
                  O(N) to reverse.
                  O(N) to re-arrange.

                  So, overall time complexity = O(N).

Space Complexity : O(1)

*/


class Solution {
public:
    
    // function to reverse the linked list
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next;
        
        while(head)
        {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    // function to return the last node of firstList, the odd even condition is taken into consideration.
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while(slow and slow -> next and fast and fast -> next)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return prev;
    }
    
     void rearrange(ListNode *firstHead, ListNode *secondHead)
    {
         int i = 0;
         ListNode *next;
        
        while(firstHead and secondHead)
        {
            if(i % 2 == 0)
            {
                next = firstHead -> next;
                firstHead -> next = secondHead;
                firstHead = next;
            }
            
            else
            {
                next = secondHead -> next;
                secondHead -> next = firstHead;
                secondHead = next;
            }
            
            i += 1;
        }
    }
    


    void reorderList(ListNode* head) 
    {

        // if Len(List) <= 2, no need to change the list, return as it is.
        if(head -> next == NULL or head -> next -> next == NULL)
            return;

        ListNode *endFirstHalf = middleNode(head);
        ListNode *secondHead = endFirstHalf -> next; //secondHalf head will point to next of last node of first half.
        secondHead = reverse(secondHead);

        // end first half by making it's last pointer pointing to null.
        endFirstHalf -> next = NULL;
        
        ListNode *firstHead = head;
        
        rearrange(firstHead, secondHead);

    }
};