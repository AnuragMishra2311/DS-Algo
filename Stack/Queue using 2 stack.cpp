/*

https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

Approach : Main stack => S1, temp stack = S2.

Push : pop s1 elements and push it into s2.
       Push x in s2.
       Pop s2 elements and push it into s1.

Pop : Return s1.top()


Time Complexity :
                Push : O(N*N)
                Pop : O(1)

*/


void StackQueue :: push(int x)
{
    while(s1.size() != 0)
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    s2.push(x);
    
    while(s2.size() != 0)
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int StackQueue :: pop()
{
    int topElement = -1;
    
        if(s1.size() != 0)
        {
            topElement = s1.top();
            s1.pop();
        }
        
        return topElement;
}