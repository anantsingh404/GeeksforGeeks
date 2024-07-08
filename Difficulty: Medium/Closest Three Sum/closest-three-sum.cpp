//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        int mini=INT_MAX;
        int ans=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++)
        {
            int sum=arr[i];
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int flag=arr[i]+arr[j]+arr[k];
                int m=abs(flag-target);
                if(m<mini)
                {   mini=m;
                    ans=flag;
                }
                if(m==mini && flag>ans)
                {
                    ans=flag;
                }
                if(flag>target)
                {
                    --k;
                }
                if(flag<target)
                {
                    ++j;
                }
                if(flag==target)
                {
                    break;
                }
                
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends