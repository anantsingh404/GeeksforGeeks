//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  static bool cmp(pair<int,int>p1,pair<int,int>p2)
  {
      if(p1.first==p2.first)
      {
          return p1.second<p2.second;
      }
      return p1.first>p2.first;
  }
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        vector<pair<int,int>>vp;
        for(auto itr:mp)
        {
            vp.push_back({itr.second,itr.first});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int>ans;
        for(int i=0;i<vp.size();i++)
        {
            int x=vp[i].first;
            while(x--)
            {
                ans.push_back(vp[i].second);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends