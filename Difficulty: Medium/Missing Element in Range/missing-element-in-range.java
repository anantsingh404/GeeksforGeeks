class Solution {
    public ArrayList<Integer> missingRange(int[] arr, int low, int high) {
        // code here
        ArrayList<Integer>ls=new ArrayList<>();
        int[] dp = new int[100001];
        Integer n=arr.length;
        Arrays.sort(arr);
        for(int i=0;i<n;i++)
        {
          dp[arr[i]]++;  
        }
        for(int i=low;i<=high;i++)
        {
            if(dp[i]==0)
            {
                ls.add(i);
            }
        }
        return ls;
       
    }
}