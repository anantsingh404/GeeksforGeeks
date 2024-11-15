//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        while(i<n && arr[i]!=0)
        {
            i++;
        }
        j=i+1;
        while(j<n && arr[j]==0)
        {
            j++;
        }
        while(j<n)
        {
            if(arr[j]!=0 && arr[i]==0)
            {
                swap(arr[j],arr[i]);
                i++;
                j++;
            }
            while(i<n && arr[i]!=0)
            {
                i++;
            }
            while(j<n && arr[j]==0)
            {
                j++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends