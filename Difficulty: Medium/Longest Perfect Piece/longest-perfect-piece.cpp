//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int nums[], int n) {
        // code here
         unordered_map<int,int>mp;
     //int n=nums.size();
     int limit=1;
     int j=0;
     int ans=1;
      priority_queue<int>pq1;
      priority_queue<int,vector<int>,greater<int>>pq2;
     for(int i=0;i<n;i++)
     {
       
       while(!pq2.empty() && nums[i]-pq2.top()>limit)
       {
        j=max(j,mp[pq2.top()]+1);
        pq2.pop();
       }
       
        while(!pq1.empty() && pq1.top()-nums[i]>limit)
        {   
            j=max(j,mp[pq1.top()]+1);
            pq1.pop();
        }
        pq2.push(nums[i]);
        pq1.push(nums[i]);
        mp[nums[i]]=i;
        ans=max(ans,i-j+1);
     }   
     return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends