// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1#


/*

Approach:  Use floyd algorithm to detect cycle, once we have fast and slow pointer pointing to same node, keep incresing
slow pointer until it reaches fast pointer again. The no. of times we need to increment slow pointer is length of loop.

Time Complexity O(N)
Space Complexity O(1)

*/

int countNodesinLoop(struct Node *head)
{
    if(!head) return 0;
    
    Node *slow=head,*fast=head;
    
    while(slow and fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) // Loop is present
        {
            int count = 1;
            slow = slow->next;
            while(slow != fast)
            {
                slow = slow->next;
                count+=1;
            }
            
            return count;
        }
    }
    return 0;
    
}


/*

Hashing 

Approach : Store nodes in map along with node position. If a node is encountered which is already present in map then 
return current positon - that node position.

Time Complexity O(N)
Space Complexity O(N)

*/

int countNodesinLoop(struct Node *head)
{
    if(!head) return 0;
    
    unordered_map<Node*,int>mp;
    Node *current = head;
    int position = 1;
    
    while(current)
    {
        if(mp.find(current)!=mp.end())
        {
            return position-mp[current];
        }
        else
        {
            mp[current]=position;
        }
        position++;
        current = current->next;
    }
    return 0;
    
}