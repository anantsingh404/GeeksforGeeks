class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                bool temp=true;
                if(i-1>=0)
                {
                    if(mat[i-1][j]>=mat[i][j])
                    {
                        temp=false;
                    }
                }
                if(i+1<mat.size())
                {
                    if(mat[i+1][j]>=mat[i][j])
                    {
                        temp=false;
                    }
                }
                if(j-1>=0)
                {
                    if(mat[i][j-1]>=mat[i][j])
                    {
                        temp=false;
                    }
                }
                if(j+1<mat[0].size())
                {
                    if(mat[i][j+1]>=mat[i][j])
                    {
                        temp=false;
                    }
                }
                if(temp)
                {
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};
