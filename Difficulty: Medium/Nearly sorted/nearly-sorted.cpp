//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
       vector<int>anss;
       int num=arr.size();
        priority_queue<int,vector<int>,greater<int>>ans;
        int j=0;
        
        for(int i=0;i<num;i++)
        {
            if(ans.size()==k+1)
            {
                arr[j]=ans.top();
                j++;
                ans.pop();
            }
            ans.push(arr[i]);
        }
        while(!ans.empty())
        {
            arr[j]=ans.top();
            ans.pop();
            j++;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends