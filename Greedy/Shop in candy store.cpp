// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1#

// If we purchase 1 candy then actually we are purchasing 1+k candies, so total candies required  = ceil(N/K+1)

vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);

        int i=0, j = N-1, count=0;
        int minimum = 0, maximum = 0;
        int required;

        required = ceil((double)N/(K+1));
        
        while(required > i)
        {
            minimum+= candies[i];
            i++;
        }
        
        while(required > count)
        {
            maximum+= candies[j];
            j--;
            count++;
        }
        
        return {minimum, maximum};
    }