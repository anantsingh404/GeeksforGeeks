//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        
      int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check mid
            if (arr[mid] == target) return mid;

            // Check left neighbor
            if (mid - 1 >= low && arr[mid - 1] == target) return mid - 1;

            // Check right neighbor
            if (mid + 1 <= high && arr[mid + 1] == target) return mid + 1;

            // Move the pointers
            if (target < arr[mid]) {
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends