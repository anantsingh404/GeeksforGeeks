class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        // code here
        int i=0;
        int j=0;
        int z=0;
        int ans=0;
        while(j<arr.length)
        {
            z=z^arr[j];if(j>=k)
            {
                z=z^arr[i++];
            }
            if(j>=k-1)
            {
                ans=Math.max(z,ans);
            }
            j++;
        }
        return ans;
    }
}
