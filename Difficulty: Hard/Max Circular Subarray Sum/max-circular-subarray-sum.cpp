class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
            int sum=0;
        int n=arr.size();
        int ans=INT_MIN;
        vector<int>left(n,INT_MIN);
        vector<int>right(n,INT_MIN);
        left[0]=arr[0];
        sum=arr[0];
        right[n-1]=arr[n-1];
        int maxi=arr[0];
        for(int i=1;i<n;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,sum);
            left[i]=maxi;
        }
        sum=arr[n-1];
        maxi=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sum+=arr[i];
            maxi=max(maxi,sum);
            right[i]=maxi;
        }
    for(int i=0;i<n-1;i++)
    {   
        ans=max(ans,left[i]+right[i+1]);
    }
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        
        ans=max(ans,sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    return ans;
    }
};