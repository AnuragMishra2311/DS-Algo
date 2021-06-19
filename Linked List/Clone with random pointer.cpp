/*

https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

https://leetcode.com/problems/copy-list-with-random-pointer/

Approach : 
VVVV Important:  While creating the nodes for cloned Linked list, map it with corresponding original nodes.

Traverse one and map all original nodes with their copy node.

Now we have our cloned LL nodes, but we need to connect them. 

Traverse through the LL again, and do following:
    Next pointer for the cloned node will point to copy of original_node->next.
    similarly, rand pointer for cloned node will point to copy of original_node->rand.

*/

// Sapce Complexity : O(N)
// Time Complexity : O(N)

Node *copyList(Node *head) 
{
    if(!head) return NULL;
    
    unordered_map<Node*, Node*>mp;
    Node *current = head, *newptr, *new_head;
    bool first_node = true;
    while(current)
    {
        newptr = new Node(current->data);
        mp[current] = newptr;
        current = current->next;
        
        if(first_node)
        {
            new_head = newptr;
            first_node = false;
        }
    }
    
    current = head;
    while(current)
    {
        mp[current]->next = mp[current->next];
        mp[current]->arb = mp[current->arb];
        current = current->next;
    }
    
    return new_head;
}