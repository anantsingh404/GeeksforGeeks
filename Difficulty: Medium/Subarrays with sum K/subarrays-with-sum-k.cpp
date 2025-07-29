class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};