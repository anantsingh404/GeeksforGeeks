class Solution {
  public:
    int balanceSums(vector<vector<int>>& matrix) {
        // code here
        int n=matrix.size();
         int count=0;
        int maxsum=0;
        int rsum=0;
        int csum=0;
        for(int i=0;i<n;i++)
        {   int sum1=0;
            for(int j=0;j<n;j++)
            {
                sum1=sum1+matrix[i][j];
            }
            rsum=max(rsum,sum1);
            int sum2=0;
            for(int j=0;j<n;j++)
            {
                sum2=sum2+matrix[j][i];
            }
            csum=max(csum,sum2);
        }
        maxsum=max(rsum,csum);
        maxsum=maxsum*n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxsum=maxsum-matrix[i][j];
            }
        }
        return maxsum;
    }
};