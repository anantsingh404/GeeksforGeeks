//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool check(int mid,int n)
    {
        int x=mid;
        int two=0;
        int five=0;
       
        while(mid>=5)
        {
            mid=mid/5;
            five+=mid;
            
        }
    two=five;
    return two>=n;
    }
        int findNum(int n)
        {
        //complete the function here
        int i=1;
        int j=INT_MAX;
        int ans=0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(check(mid,n))
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends