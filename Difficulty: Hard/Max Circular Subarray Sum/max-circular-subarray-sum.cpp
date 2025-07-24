class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        int ans=INT_MIN;
        int sum=0;
        vector<int>left(n,0);
        vector<int>right(n,0);
        int t=arr[0];
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            t+=arr[i];
            left[i]=max(left[i-1],t);
        }
        t=arr[n-1];
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            t+=arr[i];
            right[i]=max(right[i+1],t);
        }
        int i=0;
        while(i<n)
        {
            sum+=arr[i];
            ans=max(ans,sum);
            if(sum<0)
            {
                sum=0;
            }
            i++;
        }
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};