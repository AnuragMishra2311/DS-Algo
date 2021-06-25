'''
https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

Similar to kadane's algorithm.

'''
    
def maxProduct(self,arr, n):
    # code here
    min_val = arr[0]
    max_val = arr[0]
    max_pdt = arr[0]
        
    for i in range(1,n):

        if(arr[i]<0): # if -ve then swap min and max value
            min_val, max_val = max_val, min_val
          
        min_val = min(arr[i], arr[i]*min_val)
        max_val = max(arr[i], arr[i]*max_val)
            
        max_pdt = max(max_pdt, max_val)
            
    return max_pdt