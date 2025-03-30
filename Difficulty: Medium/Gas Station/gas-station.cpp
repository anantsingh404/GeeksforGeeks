//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int ts=accumulate(gas.begin(),gas.end(),0);
        int tc=accumulate(cost.begin(),cost.end(),0);
        int n=cost.size();
        if(tc>ts)
        {
            return -1;
        }
        int i=0;
        int j=0;
        int sum=0;
        while(i<n)
        {    sum+=gas[i];
            if(cost[i]<=sum)
            {
                sum-=cost[i];
            }
            else
            {
                sum=0;
                j=i+1;
            }
            i++;
        }
        return j;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends