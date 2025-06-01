class Solution {
  public:
  bool solve(vector<vector<int>>&mat,int y,int n)
  {
      int i=0;
      int j=n-1;
      while(i<=j)
      {
          int mid=(i+j)/2;
    
          if(mat[mid][0]<=y && mat[mid][n-1]>=y)
          {
              i=mid;
              break;
          }
          else if(mat[mid][0]<y)
          {
              i=mid+1;
          }
          else if(mat[mid][0]>y)
          {
              j=mid-1;
          }
          if(i==j)
          {
              break;
          }
          if(i>j)
          {
              break;
          }
      }
      if(i>=0 && i<n)
      {
          return binary_search(mat[i].begin(),mat[i].end(),y);
      }
      return false;
      
      
  }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int count=0;
        int n=mat1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int y=x-mat1[i][j];
                if(solve(mat2,y,n))
                {
                    ++count;
                }
            }
        }
        return count;
    }
};