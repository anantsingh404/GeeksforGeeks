class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int >sum=arr;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    sum[i]=max(sum[i],sum[j]+arr[i]);
                    ans=max(ans,sum[i]);
                }
            }
        }
        ans=max(ans,arr[0]);
        return ans;
        
    }
};