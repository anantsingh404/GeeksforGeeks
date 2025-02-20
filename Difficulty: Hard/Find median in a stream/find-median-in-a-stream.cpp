//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
         vector<double> ans;
    multiset<int> st;
    auto mid = st.begin();  // Iterator to track the median

    for (int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]);

        // Adjust the iterator to the correct median position
        if (st.size() == 1) {
            mid = st.begin();
        } else if (arr[i] < *mid) {
            if (st.size() % 2 == 0) {
                --mid;  // Move left if size becomes even
            }
        } else {
            if (st.size() % 2 == 1) {
                ++mid;  // Move right if size becomes odd
            }
        }

        // Compute median
        if (st.size() % 2 == 0) {
            auto nextMid = next(mid);
            ans.push_back((*mid + *nextMid) / 2.0);
        } else {
            ans.push_back(*mid);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends