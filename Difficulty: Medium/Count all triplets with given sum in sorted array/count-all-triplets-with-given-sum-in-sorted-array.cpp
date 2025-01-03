//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
       // unordered_map<int,int>mp;
       int ans=0;
       int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<i;j++)
            {
                int x=arr[i]+arr[j];
                int rem=target-x;
                if(rem<arr[i])
                {
                    continue;
                }
                else
                {
                    int x=lower_bound(arr.begin(),arr.end(),rem)-arr.begin();
                    x=max(x,i+1);
                    if(arr[x]>rem)
                    {
                        continue;
                    }
                    int y=lower_bound(arr.begin(),arr.end(),rem+1)-arr.begin();
                    ans+=y-x;
                    
                    
                    
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends