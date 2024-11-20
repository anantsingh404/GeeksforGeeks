//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int stock=prices[0];
        int sum=0;
        for(int i=1;i<prices.size();i++)
        {
           if(prices[i]<stock)
           {
               stock=prices[i];
           }
           else if(prices[i]>stock)
           {
               sum+=prices[i]-stock;
               stock=prices[i];
           }
        }
        return sum;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends