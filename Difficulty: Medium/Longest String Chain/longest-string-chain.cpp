//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
static bool cmp(const string &a, const string &b) {
    return a.size() < b.size(); // Sort words by length
}

int longestStringChain(vector<string> &words) {
    sort(words.begin(), words.end(), cmp);
    unordered_map<string, int> dp;
    int maxLength = 1;

    for (string &word : words) {
        int best = 1;
        for (int i = 0; i < word.size(); i++) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            if (dp.count(predecessor)) {
                best = max(best, dp[predecessor] + 1);
            }
        }
        dp[word] = best;
        maxLength = max(maxLength, best);
    }
    return maxLength;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends