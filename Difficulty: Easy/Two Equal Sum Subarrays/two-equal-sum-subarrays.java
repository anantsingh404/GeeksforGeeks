class Solution {
    public boolean canSplit(int arr[]) {
        // code here
        int sum=0;
        for(int i=0;i<arr.length;i++)
        {
            sum+=arr[i];
        }
        int count=0;
        for(int i=0;i<arr.length;i++)
        {
            count+=arr[i];
            if(count==sum/2 && sum%2==0)
            {
                return true;
            }
        }
        return false;
    }
}