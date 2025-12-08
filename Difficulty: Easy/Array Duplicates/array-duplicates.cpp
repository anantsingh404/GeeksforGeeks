class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i]%(n+1);
            arr[x-1]+=(n+1);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i]/(n+1)>=2)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
        
    }
};