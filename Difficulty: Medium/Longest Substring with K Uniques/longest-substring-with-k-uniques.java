class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        HashMap<Character,Integer>mp=new HashMap<>();
        int n=s.length();
        int j=0;
        int ans=-1;
        int i=0;
        while(i<n)
        {
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
            while(j<i && mp.size()>k)
            {
               mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)-1);
               if(mp.getOrDefault(s.charAt(j),0)==0)
               {
                   mp.remove(s.charAt(j));
                   
               }
               j++;
            }
            if(mp.size()==k)
            {
                ans=Math.max(i-j+1,ans);
            }
            i++;
        }
        return ans;
    }
}