class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int j=0;int k=m-1;
        
        int i=0;
        while(j<=k)
        {
            swap(mat[i][j],mat[i][k]);
            j++;
            k--;
            i++;
        }
        while(j<m && k>=0)
        {
          swap(mat[i][j],mat[i][k]);
            j++;
            k--;
            i++;  
        }
        
    }
};
