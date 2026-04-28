class Solution {
    public int longestSubstr(String s, int k) {
        // code here
      
        int n=s.length();
        HashMap<Character,Integer>mp=new HashMap<>();
        int maxi=Integer.MIN_VALUE;
        int ans=0;
        int i=0;
        int j=0;
        while(i<n)
        {
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
            int temp=mp.get(s.charAt(i));
            maxi=Math.max(maxi,temp);
            if(i-j+1-maxi>k)
            {   
           
                mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)-1);
                ++j;
            }
            ans=Math.max(ans,i-j+1);
            i++;
            
        }
        return ans;
        
        
    }
}
