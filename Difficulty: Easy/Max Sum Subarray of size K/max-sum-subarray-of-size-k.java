class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        // Code here
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        while(j<arr.length)
        {
                if(j>=k)
                {
                sum-=arr[i]; 
                i++;
                }
                sum+=arr[j];
                if(j-i+1==k)
                {
                    ans=Math.max(ans,sum);
                }
                j++;
               
            
        }
        return ans;
    }
}