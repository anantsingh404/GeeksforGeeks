class Solution {
    boolean check(int mid,int []citi,int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {if(citi[i]>=mid)
        {
            ++count;
        }
        }
        return count>=mid;
    }
    public int hIndex(int[] citi) {
        // code here
        int ans=0;
        int n=citi.length;
        int mini=0;
        int maxi=1000000;
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(check(mid,citi,n))
            {
                ans=mid;
                mini=mid+1;
            }
            else
            {
                maxi=mid-1;
            }
        }
        return ans;
    }
}