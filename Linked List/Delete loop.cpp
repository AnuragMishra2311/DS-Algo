// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/0/

/*

Hashing 
Space Complexity O(N)
Time Complexity O(N)

*/

void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        unordered_set<Node*> s;
        while(head){
            s.insert(head);
            if(s.find(head->next)!=s.end()){
                head->next=NULL;
            }
            head=head->next;
            
        }
    }




/*

Floyd 

Space Complexity O(1)
Time Complexity O(N)

Note the corner case that is loop start from first node itself.

*/


void removeLoop(Node* head)
    {

        Node *slow=head,*fast=head,*start=head;
        while(slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        
        if(slow == start) // loop starts from first node itself
        {
            while(slow->next!=start)
            {
                slow = slow->next;
            }
            slow->next = NULL;
        }
        
        else if(slow == fast)   //loop doesn't start from first node
        {
            while(slow->next!=start->next)
            {
                slow=slow->next;
                start = start->next;
            }
                slow->next =NULL;
        }
    }