class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& q) {
        // code here
        vector<int>ans;
        for(auto itr:q)
        {
          int x=itr[0];
          int y=itr[1];
          int z=itr[2];
          auto idx=lower_bound(arr.begin()+x,arr.begin()+y+1,z);
          auto idx2=upper_bound(arr.begin()+x,arr.begin()+y+1,z);
         // cout<<idx<<" "<<idx2<<endl;
          int diff=idx2-idx;
          ans.push_back(diff);
          
        }return ans;
    }
};