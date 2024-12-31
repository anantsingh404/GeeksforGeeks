//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        queue<string>pq;
        vector<vector<string>>ans;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        while(!pq.empty())
        {
            string x=pq.front();
            vector<string>vp;
            vp.push_back(x);
            pq.pop();
            vector<int>mp1(26,0);
            for(int i=0;i<x.size();i++)
            {
                mp1[x[i]-'a']++;
            }
            int n=pq.size();
            for(int i=0;i<n;i++)
            {
                string y=pq.front();
                pq.pop();
                 vector<int>mp2(26,0);
                for(int j=0;j<y.size();j++)
                {
                    mp2[y[j]-'a']++;
                }
                bool ans=true;
                if(mp1==mp2)
                {
                    vp.push_back(y);
                }
                else
                {
                  pq.push(y);  
                }
                
            }
            //sort(vp.begin(),vp.end());
            ans.push_back(vp);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends