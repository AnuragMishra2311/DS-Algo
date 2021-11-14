/*

https://leetcode.com/problems/time-needed-to-buy-tickets/


Everybody in front of person k can buy as many times as person k as long as they have tickets remaining (ie. until their tickets deplete or they buy as many as person k does, 
whichever comes first). Similarly, everybody following person k can buy one less times than person k as long as they have tickets.

Time Complexity : O(N)
Space Complexity : O(1)

*/


 int timeRequiredToBuy(vector<int>& tickets, int k) 
 {
        int person = tickets[k];
        int time = 0;
        for(int i = 0; i < tickets.size(); i++)
        {
            if(i <= k )
                time += min(tickets[i], person);
            
            else
                time += min(tickets[i], person - 1);
        }
        return time;
  }
