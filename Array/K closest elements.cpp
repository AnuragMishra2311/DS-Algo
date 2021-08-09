// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1# 
 
// Time Complexity : O(Log N + k)
 
 int binary(vector<int>arr, bool &is_present, int n, int x)
    {
        int low = 0, high = n - 1;
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == x)
            {
                is_present = true;
                return mid;
            }
            
            arr[mid]>x?high = mid - 1: low = mid + 1;
        }
        
        return high;
    }
    
    
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) 
    {
        bool is_present = false;
        int mid = binary(arr, is_present, n, x);
        int low, high, count = 0;
        vector<int>ans;
        
        if(is_present)
            low = mid - 1;
        else
            low = mid;
            
        high = mid + 1;
            
        while(low >= 0 and high < n and count!=k)
        {
            count++;
            
            if(x - arr[low] < arr[high] - x)
            {
                ans.push_back(arr[low]);
                low--;
            }
            
            else
            {
                ans.push_back(arr[high]);
                high++;
            }
        }
        
        while(low>=0 and count!=k)
        {
            count++;
            ans.push_back(arr[low]);
            low--;
        }
        
        while(high<n and count!=k)
        {
            count++;
            ans.push_back(arr[high]);
            high++;
        }
        
        return ans;
    }


// https://leetcode.com/problems/find-k-closest-elements/

    int binary(vector<int>arr, int n, int x)
    {
        int low = 0, high = n - 1;
        while(high >= low)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == x)
            {
                return mid;
            }
            
            arr[mid]>x?high = mid - 1: low = mid + 1;
        }
        
        return high;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int n = arr.size();
        int mid = binary(arr, n, x);
        int low, high, count = 0;
        vector<int>ans;
        
        low = mid;
            
        high = mid + 1;
            
        while(low >= 0 and high < n and count!=k)
        {
            count++;
            
            if(x - arr[low] <= arr[high] - x)
                low--;
            
            else 
            {
                high++;
            }
        }
        
        while(low>=0 and count!=k)
        {
            count++;
            low--;
        }
        
        while(high<n and count!=k)
        {
            count++;
            high++;
        }
        
        // Low+1 will point to starting index and right-1 will point to last index.

        for(int i=low+1; i<=high-1; i++)
        {
            ans.push_back(arr[i]);
        }
    
        
        return ans;
    }