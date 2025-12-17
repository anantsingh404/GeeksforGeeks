class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int x=arr[0][0];
        int y=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]<=y)
            {
                y=max(y,arr[i][1]);
            }
            else
            {
                ans.push_back({x,y});
                x=arr[i][0];
                y=arr[i][1];
            }
        }
        ans.push_back({x,y});
        return ans;
    }
};