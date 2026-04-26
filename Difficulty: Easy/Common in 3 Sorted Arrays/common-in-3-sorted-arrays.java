class Solution {
    public ArrayList<Integer> commonElements(int[] a, int[] b, int[] c) {
        // code here
        ArrayList<Integer>ans=new ArrayList<>();
        int i=0;
        int j=0;
        int k=0;
        int n=a.length;
        int m=b.length;
        int l=c.length;
        while(i<n && j<m && k<l)
        {
            int maxi=Math.max(a[i],b[j]);
            maxi=Math.max(maxi,c[k]);
            while(i<n && a[i]<maxi)
            {
                i++;
            }
             while(j<m && b[j]<maxi)
            {
                j++;
            }
            while(k<l && c[k]<maxi)
            {
                k++;
            }
            if(i<n && j<m && k<l && a[i]==b[j] && b[j]==c[k])
            {
                ans.add(a[i]);
            }
            while(i<n && j<m && k<l && a[i]==b[j] && b[j]==c[k])
            {
                i++;
            }
            
            
        }
        return ans;
        
    }
}