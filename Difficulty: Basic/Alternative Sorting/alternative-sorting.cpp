//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        sort(arr.rbegin(),arr.rend());
        vector<int>Ans;
        int i=0;
        int j=n-1;
        int count=0;
        while(i<=j)
        {
            if(count%2==0)
            {
                Ans.push_back(arr[i++]);
                ++count;
            }
            else
            {
                Ans.push_back(arr[j--]);
                ++count;
            }
        }
        return Ans;
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends