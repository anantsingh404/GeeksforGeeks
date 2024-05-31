//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool check(int arr[],long long mid,int n,int k)
  {
      long long count=0;
      long long sum=0;
      for(int i=0;i<n;i++)
      {
          if(sum+arr[i]>mid)
          {
              ++count;
              sum=arr[i];
          }
          else
          {
              sum+=arr[i];
          }
      }
      if(sum>0)
      {
          ++count;
      }
      return count<=k;
  }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long high=accumulate(arr,arr+n,0LL);
        long long low=*max_element(arr,arr+n);
        long long ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(arr,mid,n,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends