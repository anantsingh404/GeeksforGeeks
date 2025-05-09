//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n=arr.size();
       
        map<long,int>mp;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>k)
            {
                ++count;
            }
            if(arr[i]<=k)
            {
                --count;
            }
            if(count>0)
            {
               ans=max(ans,i+1); 
            }
            else
            {
                auto x=mp.lower_bound(count);
                if(x!=mp.begin())
                
                {
                    --x;
                }
                if(x->first<count)
                {
                    ans=max(ans,i-x->second);
                }
            }
            if(!mp.count(count))
            {
                mp[count]=i;
            }
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends