class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        // code here
        ArrayList<Integer>ls=new ArrayList<>();
        int n=a1.length;
        for(int i=0;i<n;i++)
        {
            ls.add(a1[i]-a2[i]);
        }
        HashMap<Integer,Integer>mp=new HashMap<>();
        int sum=0;
        int ans=0;
        mp.put(0,-1);
        for(int i=0;i<n;i++)
        {
           sum+=ls.get(i);
           if(mp.get(sum)!=null)
           {
               ans=Math.max(ans,i-mp.get(sum));
           }
            if(mp.get(sum)==null)
            {
                mp.put(sum,i);
            }
        }
        return ans;
        
    }
}