//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
       sort(arr.begin(),arr.end());
       int i=0;
       int n=arr.size();
       int sum=0;
       int j=n-1;
       int x=-1;
       int y=-1;
       int diff=INT_MAX;
       
       while(i<j)
       {
         sum+=arr[i]+arr[j];
         if(diff>abs(sum-target))
         {
             x=arr[i];
             y=arr[j];
             diff=abs(sum-target);
         }
         if(sum>target)
         {
             --j;
             sum=0;
         }
         else if(sum<target)
         {
           ++i;
           sum=0;
         }
         else
         {
             break;
         }
       }
       if(x==-1 && y==-1)
       {
           return {};
       }
       return {x,y};
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends