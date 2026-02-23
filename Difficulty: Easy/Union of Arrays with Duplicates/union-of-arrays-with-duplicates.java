class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        // code here
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=a.length;
        for(int i=0;i<n;i++)
        {
            mp.put(a[i],mp.getOrDefault(a[i],0)+1);
        }
        int m=b.length;
        for(int i=0;i<m;i++)
        {
            mp.put(b[i],mp.getOrDefault(b[i],0)+1);
        }
        ArrayList<Integer>ls=new ArrayList<>();
         for (Integer key : mp.keySet()) {
          ls.add(key);
}
return ls;
        
    }
}