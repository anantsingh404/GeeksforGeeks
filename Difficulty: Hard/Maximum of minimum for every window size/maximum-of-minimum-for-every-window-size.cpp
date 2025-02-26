//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
 
vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // Finding the Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        left[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    // Clear the stack for next usage
    while (!st.empty()) st.pop();

    // Finding the Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }

    // Step 2: Compute maxOfMins
    vector<int> res(n + 1, 0);  // Stores max of minimums for window sizes

    // Step 3: Fill res based on window size
    for (int i = 0; i < n; i++) {
        int window_size = right[i] - left[i] - 1;
        res[window_size] = max(res[window_size], arr[i]);
    }

    // Step 4: Fill missing values in res array
    for (int i = n - 1; i >= 1; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    // Step 5: Return result array (excluding index 0)
    return vector<int>(res.begin() + 1, res.end());
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends