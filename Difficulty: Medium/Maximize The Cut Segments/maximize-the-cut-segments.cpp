//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int yaad[10005];
    int solve(int l,int p,int q,int r){
        if(l==0)
        {
            return 0;
        }
        if(yaad[l]!=-1)
        {
            return yaad[l];
        }
        int a=INT_MIN;
        int b=INT_MIN;
        int c=INT_MIN;
        if(p<=l)
        {
            a=solve(l-p,p,q,r);
        }
        if(q<=l)
        {
            b=solve(l-q,p,q,r);
        }
        if(r<=l)
        {
            c=solve(l-r,p,q,r);
        }
        return yaad[l]=1+max({a,b,c});
}
    int maximizeTheCuts(int l, int p, int q, int r)
    {
      memset(yaad,-1,sizeof(yaad));
      int ans=solve(l,p,q,r);
      if(ans<0){
          return 0;
      }
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends