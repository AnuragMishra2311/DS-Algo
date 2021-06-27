// https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1#


/*

Logic: We will have -ve elements in reverse order from left to right. Just move all -ve elements to front one by one and our
list will be sorted.

Time Complexity : O(N)
Space Complexity : O(1)

*/
void sortList(Node** head)
{
    Node *current=*head,*prev=NULL;
    while(current)
    {
        if(current->data<0 and prev!=NULL)  // and prev condition to handle corner case when first node is -ve
        {
            prev->next = current->next;
            current->next = *head;
            *head = current;
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    
}