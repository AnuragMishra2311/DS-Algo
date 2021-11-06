/* 

https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/?

Time complexity : O(N)
Space Complexity : O(N)

*/

class Solution
{
    //Function to return the name of candidate that received maximum votes.
    public static String[] winner(String arr[], int n)
    {
    
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for( String s : arr){
            if(map.containsKey(s)){
                map.put(s, map.get(s) + 1);
            }
            
            else{
                map.put(s, 1);
            }
        }
        
        int votes = 0;
        String[] ans = new String[2];
        ans[0] = arr[0];
        Iterator<Map.Entry<String, Integer>> it = map.entrySet().iterator();
        
        while(it.hasNext()){
            Map.Entry<String, Integer> entry = it.next();
            if(entry.getValue() > votes ){
                votes = entry.getValue();
                ans[0] = entry.getKey();
                ans[1] = Integer.toString(count);
            }
            
            // Condition for candidates with same no of votes but is lexicographically small.
            else if(entry.getValue() >= votes  && ans[0].compareTo(entry.getKey()) > 0){
                ans[0] = entry.getKey();
                ans[1] = Integer.toString(count);
            }
        }
        
        return ans;
        
    }
}
