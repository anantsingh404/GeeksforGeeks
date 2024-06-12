//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int mod=1e9+7;
    int padovanSequence(int n)
    {
       //code here
       int a=1;
       int b=1;
       int c=1;
       if(n<=2)
       {
           return 1;
       }
       for(int i=3;i<=n;i++)
       {
           int x=(a%mod+b%mod)%mod;
           a=b;
           b=c;
           c=x;
           
       }
       return c%mod;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends