// https://leetcode.com/problems/linked-list-cycle-ii/

/*
Approach : Set start = head, start iterating from the point where slow and fast met.
Start incrementing start and slow by one, the intuition is slow and start will meet at beginning of loop.

Time Complexity O(N)
Space Complexity O(1)

*/


ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
        {
            return NULL;
        }
        
        ListNode *slow=head,*fast=head,*ans=NULL;
        while(slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                while(slow!=head)
                {
                    slow = slow->next;
                    head = head->next;
                }
                ans = head;
                break;
            }
        }
        return ans;
    }


/*

Hashing Approach

Time Complexity O(N)
Space COmplexity O(N)

*/

ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
        {
            return NULL;
        }
        
        ListNode* current=head,*ans=NULL;
        unordered_set<ListNode*>s;
        while(current)
        {
            if(s.find(current)!=s.end())
            {
                ans = current;
                break;
            }
            else
            {
                s.insert(current);
            }
            current = current->next;
        }
        return ans;
    }