class Solution {
    public ArrayList<Integer> findMean(int[] a, int[][] q) {
        // code here
        int n=a.length;
        int []arr=new int[n];
        arr[0]=a[0];
        for(int i=1;i<n;i++)
        {
            arr[i]=a[i]+arr[i-1];
        }
        ArrayList<Integer>ls=new ArrayList<>();
        for(int i=0;i<q.length;i++)
        {
            int x=q[i][0];
            int y=q[i][1];
            int sum=arr[y];
            if(x>0)
            {
                sum-=arr[x-1];
            }
            ls.add(sum/(y-x+1));
        }
        return ls;
    }
}