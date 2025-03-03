//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
         deque<pair<int, int>> mini, maxi;
    int start = 0, maxLength = 0;
    int left = 0;

    for (int right = 0; right < arr.size(); right++) {
        // Maintain min heap
        while (!mini.empty() && mini.back().first > arr[right])
            mini.pop_back();
        mini.push_back({arr[right], right});

        // Maintain max heap
        while (!maxi.empty() && maxi.back().first < arr[right])
            maxi.pop_back();
        maxi.push_back({arr[right], right});

        // Check condition: if the window is invalid, move the left pointer
        while (!mini.empty() && !maxi.empty() && (maxi.front().first - mini.front().first > x)) {
            if (mini.front().second == left)
                mini.pop_front();
            if (maxi.front().second == left)
                maxi.pop_front();
            left++;
        }

        // Update the longest subarray found
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }
    }

    return vector<int>(arr.begin() + start, arr.begin() + start + maxLength);
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
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends