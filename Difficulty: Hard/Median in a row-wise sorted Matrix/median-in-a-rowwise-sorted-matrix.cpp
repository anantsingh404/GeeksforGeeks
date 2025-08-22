class Solution {
  public:
  int check(vector<int>mat,int mid,int c)
{
    int l=0;
    int h=c-1;
    while(l<=h)
    {   int d=(l+h)/2;
        if(mat[d]<=mid)
        {
            l=d+1;
        }
        else
        {
            h=d-1;
        }
    }
    return l;
}
    int median(vector<vector<int>> &mat) {
        // code here
        int r=mat.size();
        int c=mat[0].size();
           int low=1;
        int high=2000;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<r;i++)
            {
                cnt+=check(mat[i],mid,c);
            }
            if(cnt<=(r*c)/2)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
        
    }
};
