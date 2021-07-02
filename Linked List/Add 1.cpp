/*

https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

Time Complexity : O(N) + O(N) + O(N)
Space Complexity : O(1)

*/


Node* reverse(Node *current)
{
    Node *prev = NULL, *next;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
} 
 
 
 Node* addOne(Node *head) 
    {
        // Reverse LL
        Node *reversed_head =  reverse(head);
        
        Node *current = reversed_head, *prev;
        
        // Add 1
        while(current and current->data == 9 )
        {
            current->data = 0;
            prev = current;
            current=current->next;
        }
        
        if(!current) // Need to add new node... 9999 wala case
        {
            Node *newptr = new Node(1);
            prev->next = newptr;
        }
        
        else
        {
            current->data = current->data+1;
        }
        
        // Again, Reverse
        return reverse(reversed_head);
    }