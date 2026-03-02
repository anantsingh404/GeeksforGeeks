class Solution 
{
    public int totalElements(int[] arr) 
    {
        // code here
        int j=0;
        int i=0;
        int n=arr.length;
        HashMap<Integer,Integer>mp=new HashMap<>();
        int ans=1;
        while(i<n)
        {
            mp.put(arr[i],mp.getOrDefault(arr[i],0)+1);
            while(j<i && mp.size()>2)
            {
               mp.put(arr[j],mp.getOrDefault(arr[j],0)-1); 
               if(mp.get(arr[j])==0)
               {
                   mp.remove(arr[j]);
               }
               j++;
            }
            ans=Math.max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }
}