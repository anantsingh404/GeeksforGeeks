//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
         long long ans = 0;
    int sign = 1; // Default to positive
    int started = 0; // To track if the number parsing has started

    // Skip leading whitespace
    while (*s == ' ') {
        s++;
    }

    // Check for sign
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }

    // Parse digits
    while (*s >= '0' && *s <= '9') {
        ans = ans * 10 + (*s - '0');

        // Clamp the value to avoid overflow
        if (ans * sign > INT_MAX) {
            return INT_MAX;
        }
        if (ans * sign < INT_MIN) {
            return INT_MIN;
        }

        s++;
        started = 1;
    }

    return (int)(ans * sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends