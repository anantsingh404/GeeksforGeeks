class Solution {
  public:
    int assignHole(vector<int>& mice, vector<int>& holes) {
        // code here
        sort(mice.begin(),mice.end());
        sort(holes.begin(),holes.end());
        int ans=INT_MIN;
        for(int i=0;i<mice.size();i++)
        {
            ans=max(ans,abs(holes[i]-mice[i]));
        }
        return ans;
    }
};