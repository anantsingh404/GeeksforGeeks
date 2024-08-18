//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long sum=accumulate(arr.begin(),arr.end(),1LL*0);
        long long flag=0;
        if(sum%2)
        {
            return false;
        }
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            flag+=arr[i];
            if(i<n-1 && flag==sum/2)
            {
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends