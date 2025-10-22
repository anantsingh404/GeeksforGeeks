class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
       vector<pair<long long,vector<int>>>vp;
       for(int i=0;i<points.size();i++)
       {
           long long x=pow(abs(points[i][0]),2)+pow(abs(points[i][1]),2);
           vp.push_back({x,points[i]});
       }
       sort(vp.begin(),vp.end());
       vector<vector<int>>ans;
       for(int i=0;i<k;i++)
       {
          ans.push_back(vp[i].second);
       }
       return ans;
    }
};