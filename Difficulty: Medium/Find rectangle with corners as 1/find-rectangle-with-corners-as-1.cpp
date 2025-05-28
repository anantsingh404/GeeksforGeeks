class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                for(int k=j+1;k<m;k++)
                {
                  if(mat[i][j]==1 && mat[i][k]==1)
                  {
                      mp[{j,k}]++;
                      if(mp[{j,k}]>1)
                      {
                          return true;
                      }
                  }
                }
            }
        }
        return false;
    }
};