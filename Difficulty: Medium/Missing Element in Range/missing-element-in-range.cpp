class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i=low;i<=high;i++)
        {
            int idx=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            if(idx==arr.size())
            {
                ans.push_back(i);continue;
            }
            if(arr[idx]!=i)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};