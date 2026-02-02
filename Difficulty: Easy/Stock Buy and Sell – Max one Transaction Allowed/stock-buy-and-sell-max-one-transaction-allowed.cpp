class Solution {
  public:
    int maxProfit(vector<int> &arr) {
        // code here
        int mini=arr[0];
        int ans=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>mini)
            {
                ans=max(ans,arr[i]-mini);
                mini=min(mini,arr[i]);
            }
            else
            {
              mini=min(mini,arr[i]);  
            }
        }
        return ans;
    }
};
