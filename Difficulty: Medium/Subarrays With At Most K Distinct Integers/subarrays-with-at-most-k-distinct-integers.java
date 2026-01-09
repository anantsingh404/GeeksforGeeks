class Solution {
    public int countAtMostK(int arr[], int k) {
        // code here
        Map<Integer,Integer>mp=new HashMap<>();
        int n=arr.length;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {  if(mp.get(arr[i])==null)
        {
            mp.put(arr[i],1);
        }
        else{
            mp.put(arr[i],mp.get(arr[i])+1);
            
        }
            while(j<=i&& mp.size()>k)
            {
                mp.put(arr[j],mp.get(arr[j])-1);
                if(mp.get(arr[j]).equals(0))
                {
                    mp.remove(arr[j]);
                }
                j++;
                
            }
            ans+=(i-j+1);
            
            
        }
        return ans;
        
        
    }
}
