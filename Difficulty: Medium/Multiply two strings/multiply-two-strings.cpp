//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

   string multiplyStrings(string& s1, string& s2) {
    // Handle negative numbers
    bool neg = false;
    if (s1[0] == '-') {
        neg = !neg;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        neg = !neg;
        s2 = s2.substr(1);
    }

    if (s1 == "0" || s2 == "0") {
        return "0";
    }

    string ans;
    int n = s2.size();
    int m = s1.size();

    for (int i = n - 1; i >= 0; i--) {
        string res = "";
        int x = s2[i] - '0';
        int carry = 0;

        for (int j = m - 1; j >= 0; j--) {
            int y = s1[j] - '0';
            int temp = y * x;
            temp += carry;
            int z = temp % 10;
            carry = temp / 10;
            res += (z + '0');
        }

        reverse(res.begin(), res.end());

        while (carry > 0) {
            res = char(carry % 10 + '0') + res;
            carry = carry / 10;
        }

        // Add zeros based on the position
        for (int k = 0; k < n - 1 - i; k++) {
            res.push_back('0');
        }

        // Now add res to ans
        if (ans.empty()) {
            ans = res;
        } else {
            string temp = "";
            int carry = 0;
            int p1 = ans.size() - 1;
            int p2 = res.size() - 1;

            while (p1 >= 0 || p2 >= 0 || carry) {
                int sum = carry;
                if (p1 >= 0) sum += ans[p1--] - '0';
                if (p2 >= 0) sum += res[p2--] - '0';
                temp.push_back((sum % 10) + '0');
                carry = sum / 10;
            }
            reverse(temp.begin(), temp.end());
            ans = temp;
        }
    }

    // Remove leading zeros
    int idx = 0;
    while (idx < ans.size() && ans[idx] == '0') {
        idx++;
    }
    if(idx<ans.size()){
    ans = ans.substr(idx);
    }
    else
    {
        return "0";
    }

    if (neg) {
        ans = "-" + ans;
    }

    return ans;
}

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends