//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int n=arr.size();
        int exor=0;
        for(int i=0;i<arr.size();i++)
        {
             exor=arr[i]^exor;
             
        }
        int setbit=-1;
        for(int i=0;i<32;i++)
        {
            if(exor&(1<<i))
            {
                setbit=i;
                break;
            }
        }
        int first=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&(1<<setbit))
            {
                first=first^arr[i];
            }
           
        }
        int second=first^exor;
        return {min(first,second),max(first,second)};
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends