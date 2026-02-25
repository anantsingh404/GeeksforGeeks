class Solution {
    public int longestSubarray(int[] arr, int k) {
        // Code Here
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=arr.length;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>k)
            {
                ++ans;
            }
            else
            {
                --ans;
            }
            if(ans>0)
            {
                count=Math.max(count,i+1);
            }
            else if(mp.containsKey(ans-1))
            {
                count=Math.max(count,(i-(mp.get(ans-1))));
            }
            if(!mp.containsKey(ans))
            {
                mp.put(ans,i);
            }
               
        }
        return count;
        
    }
}