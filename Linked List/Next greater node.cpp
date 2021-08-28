
/*

https://leetcode.com/problems/next-greater-node-in-linked-list/

Approach: Reverse the LL

The elements in stack will always be in increasing order.
Do the following:
    1. keep popping until stack is not empty and s.top < arr[i]
    2. if stack is empty, ans[i] = 0 else ans[i] = s.top
    3. push arr[i] into stack
    
Time Complexity  : O(N)
Space Complexity : O(N)

*/


ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL, *next, *current = head;
    
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}


 vector<int> nextLargerNodes(ListNode* head) 
    {
        ListNode *rh =  reverse(head);
        vector<int>ans;
        stack<int>s;
        
        while(rh)
        {
            while(!s.empty() and rh->val >= s.top())
            {
                s.pop();
            }
            
            s.empty()?ans.push_back(0):ans.push_back(s.top());
            
            s.push(rh->val);
            
            rh = rh -> next;
        }
   
        reverse(ans.begin(), ans.end());
        return ans;
    }
