class Solution {
    public int visibleBuildings(int arr[]) {
        // code here
        int n=arr.length;
        int maxi=-1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(maxi<=arr[i])
            {
                ++count;
            }
            maxi=Math.max(maxi,arr[i]);
        }
        return count;
    }
}