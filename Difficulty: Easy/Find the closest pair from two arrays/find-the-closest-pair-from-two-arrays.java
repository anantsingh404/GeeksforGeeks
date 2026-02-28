class Solution {
    public static ArrayList<Integer> findClosestPair(int arr[], int brr[], int x) {
        // code here
        int first=-1;
        int second=-1;
        int n=arr.length;
        int m=brr.length;
        int i=0;
        int j=m-1;
        int ans=100000000;
        int sum=arr[0]+brr[m-1];
        while(i<n && j>=0)
        {
            sum=arr[i]+brr[j];
            if(ans>Math.abs(sum-x))
            {
                ans=Math.abs(sum-x);
                first=arr[i];
                second=brr[j];
            }
            if(sum<=x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        ArrayList<Integer>ls=new ArrayList<>();
        ls.add(first);
        ls.add(second);
        return ls;
    }
}