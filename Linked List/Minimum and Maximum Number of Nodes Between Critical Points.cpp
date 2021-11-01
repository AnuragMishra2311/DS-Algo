/*
 
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

Time Complexity : O(N)
Space Complexity : O(1)

*/
 
 vector<int> nodesBetweenCriticalPoints(ListNode* head) 
 {
        int count = 1, minimum_distance = INT_MAX, maximum_distance = INT_MIN;
        int prev = -1, first;
        
        while(head and head->next and head->next->next)
        {
            // When pointing to head we are checking if head->next is critical point or not.


            // Condition for critical point.
            if ( (head->next->val > head->val and head->next->next->val < head->next->val)  or 
                (head->next->val < head->val and head->next->next->val > head->next->val))
            {
                // For first critical point.
                if(prev != -1)
                {
                    minimum_distance = min(minimum_distance, count - prev);
                    maximum_distance = max(maximum_distance, count - first);
                }
                
                else
                    first = count;
                
                prev = count;

            }
            
            
            head = head -> next;
            count += 1;
        }
        
        if(minimum_distance == INT_MAX)
            return {-1,-1};
        
        return {minimum_distance, maximum_distance};
    }