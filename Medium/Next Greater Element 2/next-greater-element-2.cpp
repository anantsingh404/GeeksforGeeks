//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& nums) {
        
        //int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>flag;
        for(int i=n-1;i>=0;i--)
        {
        flag.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!flag.empty() && flag.top()<=nums[i])
            {
            flag.pop();
            }
            if(flag.empty())
            {
                ans[i]=-1;
            }
            else {
               ans[i]=flag.top();
            }
           
            flag.push(nums[i]);
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
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends