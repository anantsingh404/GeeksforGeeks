//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1)
            {
                ++sum;
            }
            if(arr[i]==0)
            {
                --sum;
            }
            if(sum==0)
            {
                ans=i+1;
            }
            if(mp[sum]>0)
            {
                ans=max(ans,i+1-mp[sum]);
            }
            if(mp[sum]<1)
            {
                mp[sum]=i+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends