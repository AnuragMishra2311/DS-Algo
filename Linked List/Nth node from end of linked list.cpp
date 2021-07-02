/*

Simple Approach : Find the length of LL and then find nth node from the end.

*/


int get_length(Node *head)
{
    int length;
    if(head==NULL)
        return 0;

    else
        length=1+get_length(head->next);

    return length;
}

int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *temp=head;
       int length=get_length(temp);

       int check=length+1-n,counter=1;
       while(head && counter<=check)
       {
           if(counter==check)
           {
               return head->data;
           }

           head=head->next;
           counter+=1;
       }
       return -1;
}



/*

Better Approach

Initialize reference pointer with head, keep track of count.

If count<n keep incrementing reference.

if cnt>=n increment both, reference and head. 

Intuition: Head pointer starts incrementing when reference pointer has reached nth node. There is gap of n nodes between
reference and head node. So, when reference pointer will reach end then head pointer will point to nth node from end.

*/

int getNthFromLast(Node *head, int n)
{
    Node *reference=head;
    int cnt=0, length = 0;
    while(reference)
    {
        if(cnt<n)
        {
            reference = reference->next;
        }
        
        else
        {
            head = head->next;
            reference = reference->next;
        }
        cnt++;
        
        length++;
    }
    
    return n>length?-1:head->data;

}